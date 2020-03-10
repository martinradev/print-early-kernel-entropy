#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/start_kernel.h>
#include <linux/kallsyms.h>
#include <linux/pfn.h>
#include <linux/highmem.h>
#include <linux/cpumask.h>
#include <linux/percpu-defs.h>
#include <linux/sched/signal.h>
#include <linux/sched.h>
#include <asm/kaslr.h>
#include <asm/processor.h>
MODULE_LICENSE("GPL");

#define PRINT_KASLR_ADDRESS "print_kaslr: "

static int __init print_kaslr_offsets_init(void)
{
	 int cpu;
	 unsigned long canary;
	 struct task_struct *p;
	 int process_idx = 0;

	 // First print the kaslr virtual and physical addresses.
	 // These should be random and not-correlated.
	 u64 text_start = kallsyms_lookup_name("_text");
	 u64 text_start_phys = virt_to_phys((volatile void*)text_start);
	 printk(PRINT_KASLR_ADDRESS "_text virt_addr: %llx\n", text_start);
	 printk(PRINT_KASLR_ADDRESS "_text phys_addr: %llx\n", text_start_phys);

	 // Now traverse the kaslr memory regions:
	 // page_offset_base, vmalloc_base, vmemmap_base
	 printk(PRINT_KASLR_ADDRESS "page_offset_base: %lx\n", page_offset_base);
	 printk(PRINT_KASLR_ADDRESS "vmalloc_base: %lx\n", vmalloc_base);
	 printk(PRINT_KASLR_ADDRESS "vmemmap_base: %lx\n", vmemmap_base);

     // Unfortunately, on 4.15.0 the irq_stack_union per-CPU symbol doesn't seem to be accessible.
     // This is a temporary hack to make the module loadable.
#if 0
	 for_each_present_cpu(cpu)
	 {
		canary = per_cpu(irq_stack_union.stack_canary, cpu);	
		printk(PRINT_KASLR_ADDRESS "boot/irq_stack cpu %d canary: %lx\n", cpu, canary);
	 }
#endif

	 for_each_process(p)
	 {
		printk(PRINT_KASLR_ADDRESS "Task pid %d. canary: %lx", p->pid, p->stack_canary);
		if (++process_idx >= 16)
		{
			break;
		}
	 }

	 return 0;
}

static void __exit print_kaslr_offsets_exit(void) {
	printk(PRINT_KASLR_ADDRESS "done\n");
}

module_init(print_kaslr_offsets_init);
module_exit(print_kaslr_offsets_exit);
