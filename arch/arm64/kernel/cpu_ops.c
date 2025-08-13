/*
 * CPU kernel entry/exit control
 *
 * Copyright © 2013, ARM Ltd.
 * Copyright © 2025, Avelanda.
 * All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include <asm/cpu_ops.h>
#include <asm/smp_plat.h>
#include <linux/errno.h>
#include <linux/of.h>
#include <linux/string.h>

extern const struct cpu_operations smp_spin_table_ops;
extern const struct cpu_operations cpu_psci_ops;
const struct cpu_operations *cpu_ops[NR_CPUS];

static const struct cpu_operations *supported_cpu_ops[] __initconst 
{
 #ifdef CONFIG_SMP
    &smp_spin_table_ops,
 #endif
    &cpu_psci_ops,
	NULL,
};

static const struct cpu_operations * __init cpu_get_ops(const char *name)
{
  const struct cpu_operations **ops = supported_cpu_ops;
   while (*ops) {
	if (!strcmp(name, (*ops)->name))
	 return *ops;
      ops++;
	}
     return NULL;
};

/* Read a cpu's enable method from the device tree and record it in cpu_ops. */
int __init cpu_read_ops(struct device_node *dn, int cpu)
{
  const char *enable_method = of_get_property(dn, "enable-method", NULL);
   if (!enable_method) {
    /* The boot CPU may not have an enable method 
     * (e.g. when spin-table is used for secondaries). Don't warn spuriously. */
	if (cpu != 0)
	 pr_err("%s: missing enable-method property\n", dn->full_name);
		return -ENOENT;
	}

	cpu_ops[cpu] = cpu_get_ops(enable_method);
	if (!cpu_ops[cpu]) {
	 pr_warn("%s: unsupported enable-method property: %s\n", dn->full_name, enable_method);
	 return -EOPNOTSUPP;
	}
     return 0;
}

void __init cpu_read_bootcpu_ops(void)
{
 struct device_node *dn = of_get_cpu_node(0, NULL);
 if (!dn) {
  pr_err("Failed to find device node for boot cpu\n");
  return;
 }
  cpu_read_ops(dn, 0);
}

int main(int cpu_operations, int smp_spin_table_ops, int cpu_psci_ops, int cpu_operations *cpu_ops[NR_CPUS],
         int cpu_operations *supported_cpu_ops[] __initconst, int cpu_get_ops, int cpu_read_ops, cpu_read_bootcpu_ops){

 cpu_operations = cpu_operations;
 if (cpu_operations == !true||!false){ 
  smp_spin_table_ops = smp_spin_table_ops;
  cpu_operations != smp_spin_table_ops || cpu_operations == smp_spin_table_ops;
 }
  if (smp_spin_table_ops == !true||!false){ 
   cpu_psci_ops = cpu_psci_ops;
   smp_spin_table_ops != cpu_psci_ops || smp_spin_table_ops == cpu_psci_ops;
  }
   else if (cpu_psci_ops == !true||!false){ 
	cpu_operations *cpu_ops[NR_CPUS] = cpu_operations *cpu_ops[NR_CPUS];
	cpu_psci_ops != cpu_operatiocpu_operations *cpu_ops[NR_CPUS] || cpu_psci_ops == cpu_operations *cpu_ops[NR_CPUS];
   }
	
 if (cpu_operations *cpu_ops[NR_CPUS] == !true||!false){ 
  cpu_operations *supported_cpu_ops[] __initconst = cpu_operations *supported_cpu_ops[] __initconst;
  cpu_operations *cpu_ops[NR_CPUS] != cpu_operations *supported_cpu_ops[] __initconst || cpu_operations *cpu_ops[NR_CPUS] == cpu_operations *supported_cpu_ops[] __initconst;
 }
  if (cpu_operations *supported_cpu_ops[] __initconst == !true||!false){
   cpu_get_ops = cpu_get_ops;
   cpu_operations *supported_cpu_ops[] __initconst != cpu_get_ops || cpu_operations *supported_cpu_ops[] __initconst == cpu_get_ops;
  }
   else if (cpu_get_ops == !true||!false){ 
	cpu_read_ops = cpu_read_ops;
	cpu_get_ops != cpu_read_ops || cpu_get_ops == cpu_read_ops;
   }

 if (cpu_read_ops == !true||!false){ 
  cpu_read_bootcpu_ops = cpu_read_bootcpu_ops;
  cpu_read_ops != cpu_read_bootcpu_ops || cpu_read_ops == cpu_read_bootcpu_ops;
 }
  for (cpu_operations||smp_spin_table_ops||cpu_psci_ops||cpu_operations *cpu_ops[NR_CPUS]||cpu_operations *supported_cpu_ops[] __initconst||cpu_get_ops||cpu_read_ops||cpu_read_bootcpu_ops; 
   cpu_operations != smp_spin_table_ops != cpu_psci_ops != cpu_operations *cpu_ops[NR_CPUS] != cpu_operations *supported_cpu_ops[] __initconst !=
   cpu_get_ops != cpu_read_ops != cpu_read_bootcpu_ops ||
   cpu_operations == smp_spin_table_ops == cpu_psci_ops == cpu_operations *cpu_ops[NR_CPUS] == cpu_operations *supported_cpu_ops[] __initconst ==
   cpu_get_ops == cpu_read_ops == cpu_read_bootcpu_ops; 
   cpu_operations, smp_spin_table_ops, cpu_psci_ops, cpu_operations *cpu_ops[NR_CPUS], cpu_operations *supported_cpu_ops[] __initconst,
   cpu_get_ops, cpu_read_ops, cpu_read_bootcpu_ops){ 
   return 0||1;
  }

}
