/****************************/
/* THIS IS OPEN SOURCE CODE */
/****************************/

/* 
* File:    freebsd-map-k8.c
* CVS:     $Id$
* Author:  Harald Servat
*          harald.servat@gmail.com
*/

#include SUBSTRATE
#include "papiStdEventDefs.h"
#include "map.h"


/****************************************************************************
 K8 SUBSTRATE 
 K8 SUBSTRATE 
 K8 SUBSTRATE (aka Athlon64)
 K8 SUBSTRATE
 K8 SUBSTRATE
****************************************************************************/

/*
	NativeEvent_Value_K8Processor must match K8Processor_info 
*/

Native_Event_LabelDescription_t K8Processor_info[] =
{
	{ "k8-bu-cpu-clk-unhalted", "Count the number of clock cycles when the CPU is not in the HLT or STPCLCK states" },
	{ "k8-bu-fill-request-l2-miss", "Count fill requests that missed in the L2 cache."},
	{ "k8-bu-internal-l2-request", "Count internally generated requests to the L2 cache." },
	{ "k8-dc-access", "Count data cache accesses including microcode scratchpad accesses."},
	{ "k8-dc-copyback", "Count data cache copyback operations."},
	{ "k8-dc-dcache-accesses-by-locks", "Count data cache accesses by lock instructions." },
	{ "k8-dc-dispatched-prefetch-instructions", "Count the number of dispatched prefetch instructions." },
	{ "k8-dc-l1-dtlb-miss-and-l2-dtlb-hit", "Count L1 DTLB misses that are L2 DTLB hits." },
	{ "k8-dc-l1-dtlb-miss-and-l2-dtlb-miss", "Count L1 DTLB misses that are also misses in the L2 DTLB." },
	{ "k8-dc-microarchitectural-early-cancel-of-an-access", "Count microarchitectural early cancels of data cache accesses." },
	{ "k8-dc-microarchitectural-late-cancel-of-an-access", "Count microarchitectural late cancels of data cache accesses." },
	{ "k8-dc-misaligned-data-reference", "Count misaligned data references." },
	{ "k8-dc-miss", "Count data cache misses."},
	{ "k8-dc-one-bit-ecc-error", "Count one bit ECC errors found by the scrubber." },
	{ "k8-dc-refill-from-l2", "Count data cache refills from L2 cache." },
	{ "k8-dc-refill-from-system", "Count data cache refills from system memory." },
	{ "k8-fp-dispatched-fpu-ops", "Count the number of dispatched FPU ops." },
	{ "k8-fp-cycles-with-no-fpu-ops-retired", "Count cycles when no FPU ops were retired." },
	{ "k8-fp-dispatched-fpu-fast-flag-ops", "Count dispatched FPU ops that use the fast flag interface." },
	{ "k8-fr-decoder-empty", "Count cycles when there was nothing to dispatch." },
	{ "k8-fr-dispatch-stalls", "Count all dispatch stalls." },
	{ "k8-fr-dispatch-stall-for-segment-load", "Count dispatch stalls for segment loads." },
	{ "k8-fr-dispatch-stall-for-serialization", "Count dispatch stalls for serialization." },
	{ "k8-fr-dispatch-stall-from-branch-abort-to-retire", "Count dispatch stalls from branch abort to retiral." },
	{ "k8-fr-dispatch-stall-when-fpu-is-full", "Count dispatch stalls when the FPU is full." },
	{ "k8-fr-dispatch-stall-when-ls-is-full", "Count dispatch stalls when the load/store unit is full." },
	{ "k8-fr-dispatch-stall-when-reorder-buffer-is-full", "Count dispatch stalls when the reorder buffer is full." },
	{ "k8-fr-dispatch-stall-when-reservation-stations-are-full", "Count dispatch stalls when reservation stations are full." },
	{ "k8-fr-dispatch-stall-when-waiting-for-all-to-be-quiet", "Count dispatch stalls when waiting for all to be quiet." },
	{ "k8-fr-dispatch-stall-when-waiting-far-xfer-or-resync-branch-pending", "Count dispatch stalls when a far control transfer or a resync branch is pending." },
	{ "k8-fr-fpu-exceptions", "Count FPU exceptions." },
	{ "k8-fr-interrupts-masked-cycles", "Count cycles when interrupts were masked." },
	{ "k8-fr-interrupts-masked-while-pending-cycles", "Count cycles while interrupts were masked while pending" },
	{ "k8-fr-number-of-breakpoints-for-dr0", "Count the number of breakpoints for DR0." },
	{ "k8-fr-number-of-breakpoints-for-dr1", "Count the number of breakpoints for DR1." },
	{ "k8-fr-number-of-breakpoints-for-dr2", "Count the number of breakpoints for DR2." },
	{ "k8-fr-number-of-breakpoints-for-dr3", "Count the number of breakpoints for DR3." },
	{ "k8-fr-retired-branches", "Count retired branches including exceptions and interrupts." },
	{ "k8-fr-retired-branches-mispredicted", "Count mispredicted retired branches." },
	{ "k8-fr-retired-far-control-transfers", "Count retired far control transfers" },
	{ "k8-fr-retired-fastpath-double-op-instructions", "Count retired fastpath double op instructions." },
	{ "k8-fr-retired-fpu-instructions", "Count retired FPU instructions." },
	{ "k8-fr-retired-near-returns", "Count retired near returns." },
	{ "k8-fr-retired-near-returns-mispredicted", "Count mispredicted near returns." },
	{ "k8-fr-retired-resyncs", "Count retired resyncs" },
	{ "k8-fr-retired-taken-hardware-interrupts", "Count retired taken hardware interrupts."},
	{ "k8-fr-retired-taken-branches", "Count retired taken branches." },
	{ "k8-fr-retired-taken-branches-mispredicted", "Count retired taken branches that were mispredicted." },
	{ "k8-fr-retired-taken-branches-mispredicted-by-addr-miscompare", "Count retired taken branches that were mispredicted only due to an address miscompare." },
	{ "k8-fr-retired-uops", "Count retired uops." },
	{ "k8-fr-retired-x86-instructions", "Count retired x86 instructions including exceptions and interrupts"},
	{ "k8-ic-fetch", "Count instruction cache fetches." },
	{ "k8-ic-instruction-fetch-stall", "Count cycles in stalls due to instruction fetch." },
	{ "k8-ic-l1-itlb-miss-and-l2-itlb-hit", "Count L1 ITLB misses that are L2 ITLB hits." },
	{ "k8-ic-l1-itlb-miss-and-l2-itlb-miss", "Count ITLB misses that miss in both L1 and L2 ITLBs." },
	{ "k8-ic-microarchitectural-resync-by-snoop", "Count microarchitectural resyncs caused by snoops." },
	{ "k8-ic-miss", "Count instruction cache misses." },
	{ "k8-ic-refill-from-l2", "Count instruction cache refills from L2 cache." },
	{ "k8-ic-refill-from-system", "Count instruction cache refills from system memory." },
	{ "k8-ic-return-stack-hits", "Count hits to the return stack." },
	{ "k8-ic-return-stack-overflow", "Count overflows of the return stack." },
	{ "k8-ls-buffer2-full", "Count load/store buffer2 full events." },
	{ "k8-ls-locked-operation", "Count locked operations." },
	{ "k8-ls-microarchitectural-late-cancel", "Count microarchitectural late cancels of operations in the load/store unit" },
	{ "k8-ls-microarchitectural-resync-by-self-modifying-code", "Count microarchitectural resyncs caused by self-modifying code." },
	{ "k8-ls-microarchitectural-resync-by-snoop", "Count microarchitectural resyncs caused by snoops." },
	{ "k8-ls-retired-cflush-instructions", "Count retired CFLUSH instructions." },
	{ "k8-ls-retired-cpuid-instructions", "Count retired CPUID instructions." },
	{ "k8-ls-segment-register-load", "Count segment register loads." },
	{ "k8-nb-memory-controller-bypass-saturation", "Count memory controller bypass counter saturation events." },
	{ "k8-nb-memory-controller-dram-slots-missed", "Count memory controller DRAM command slots missed (in MemClks)." },
	{ "k8-nb-memory-controller-page-access-event", "Count memory controller page access events." },
	{ "k8-nb-memory-controller-page-table-overflow", "Count memory control page table overflow events." },
	{ "k8-nb-probe-result", "Count probe events." },
	{ "k8-nb-sized-commands", "Count sized commands issued." },
	{ "k8-nb-memory-controller-turnaround", "Count memory control turnaround events." },
	{ "k8-nb-ht-bus0-bandwidth", "Count events on the HyperTransport(tm) bus #0" },
	{ "k8-nb-ht-bus1-bandwidth", "Count events on the HyperTransport(tm) bus #1" },
	{ "k8-nb-ht-bus2-bandwidth", "Count events on the HyperTransport(tm) bus #2" },
	/* Special counters with some masks activated */
	{ "k8-dc-refill-from-l2,mask=+modified,+owner,+exclusive,+shared", "Count data cache refills from L2 cache (in MOES state)." },
	{ "k8-dc-refill-from-l2,mask=+owner,+exclusive,+shared", "Count data cache refills from L2 cache (in OES state)." },
	{ "k8-dc-refill-from-l2,mask=+modified", "Count data cache refills from L2 cache (in M state)." },
	{ "k8-dc-refill-from-system,mask=+modified,+owner,+exclusive,+shared", "Count data cache refills from system memory (in MOES state)." },
	{ "k8-dc-refill-from-system,mask=+owner,+exclusive,+shared", "Count data cache refills from system memory (in OES state)." },
	{ "k8-dc-refill-from-system,mask=+modified", "Count data cache refills from system memory (in M state)." },
	{ "k8-fp-dispatched-fpu-ops,mask=+multiply-pipe-junk-ops", "Count the number of dispatched FPU multiplies." },
	{ "k8-fp-dispatched-fpu-ops,mask=+add-pipe-junk-ops", "Count the number of dispatched FPU adds." },
	{ "k8-fp-dispatched-fpu-ops,mask=+multiply-pipe-junk-ops,+add-pipe-junk-ops", "Count the number of dispatched FPU adds and multiplies." },
	{ NULL, NULL }
};

/* PAPI PRESETS */
hwi_search_t K8Processor_map[] = {
	{PAPI_BR_INS, {0, {PNE_K8_FR_RETIRED_BRANCHES}, {0,}}},
	{PAPI_RES_STL, {0, {PNE_K8_FR_DISPATCH_STALLS}, {0,}}},
	{PAPI_TOT_CYC, {0, {PNE_K8_BU_CPU_CLK_UNHALTED}, {0,}}},
	{PAPI_TOT_INS, {0, {PNE_K8_FR_RETIRED_X86_INSTRUCTIONS}, {0,}}},
	{PAPI_STL_ICY,{0, {PNE_K8_FR_DECODER_EMPTY}, {0,}}},
	{PAPI_HW_INT, {0, {PNE_K8_FR_RETIRED_TAKEN_HARDWARE_INTERRUPTS}, {0,}}},
	{PAPI_BR_TKN, {0, {PNE_K8_FR_RETIRED_TAKEN_BRANCHES}, {0,}}},
	{PAPI_BR_MSP, {0, {PNE_K8_FR_RETIRED_TAKEN_BRANCHES_MISPREDICTED}, {0,}}},

	{PAPI_TLB_DM, {0, {PNE_K8_DC_L1_DTLB_MISS_AND_L2_DTLB_MISS}, {0,}}},
	{PAPI_TLB_IM, {0, {PNE_K8_IC_L1_ITLB_MISS_AND_L2_ITLB_MISS}, {0,}}},
#if HWPMC_NUM_COUNTERS >= 2
	{PAPI_TLB_TL, {DERIVED_ADD, {PNE_K8_DC_L1_DTLB_MISS_AND_L2_DTLB_MISS,PNE_K8_IC_L1_ITLB_MISS_AND_L2_ITLB_MISS},{0,}}},
#endif

	{PAPI_L1_DCA, {0, {PNE_K8_DC_ACCESS}, {0,}}},
	{PAPI_L1_ICA, {0, {PNE_K8_IC_FETCH}, {0,}}},
#if HWPMC_NUM_COUNTERS >= 2
	{PAPI_L1_TCA, {DERIVED_ADD, {PNE_K8_DC_ACCESS, PNE_K8_IC_FETCH}, {0,}}},
#endif
	{PAPI_L1_ICR, {0, {PNE_K8_IC_FETCH}, {0,}}},
	{PAPI_L2_ICH, {0, {PNE_K8_IC_REFILL_FROM_L2}, {0,}}},
	{PAPI_L2_DCH, {0, {PNE_K8_DC_REFILL_FROM_L2}, {0,}}},
	{PAPI_L2_DCM, {0, {PNE_K8_DC_REFILL_FROM_SYSTEM_MOES}, {0,}}},
#if HWPMC_NUM_COUNTERS >= 2
	{PAPI_L2_DCA, {DERIVED_ADD, {PNE_K8_DC_REFILL_FROM_SYSTEM_MOES, PNE_K8_DC_REFILL_FROM_L2_MOES}, {0,}}},
#endif
	{PAPI_L2_ICM, {0, {PNE_K8_IC_REFILL_FROM_SYSTEM}, {0,}}},
	{PAPI_L2_DCR, {0, {PNE_K8_DC_REFILL_FROM_L2_OES}, {0,}}},
	{PAPI_L2_DCW, {0, {PNE_K8_DC_REFILL_FROM_L2_M}, {0,}}},
	{PAPI_L2_DCH, {0, {PNE_K8_DC_REFILL_FROM_L2_MOES},{0,}}},
	{PAPI_L1_LDM, {0, {PNE_K8_DC_REFILL_FROM_L2_OES},{0,}}},
	{PAPI_L1_STM, {0, {PNE_K8_DC_REFILL_FROM_L2_M},{0,}}},
	{PAPI_L2_LDM, {0, {PNE_K8_DC_REFILL_FROM_SYSTEM_OES},{0,}}},
	{PAPI_L2_STM, {0, {PNE_K8_DC_REFILL_FROM_SYSTEM_M},{0,}}},
#if HWPMC_NUM_COUNTERS >= 2
	{PAPI_L1_DCM, {DERIVED_ADD, {PNE_K8_DC_REFILL_FROM_SYSTEM_MOES, PNE_K8_DC_REFILL_FROM_L2_MOES}, {0,}}},
	{PAPI_L1_ICM, {DERIVED_ADD, {PNE_K8_IC_REFILL_FROM_L2, PNE_K8_IC_REFILL_FROM_SYSTEM}, {0,}}},
#endif
#if HWPMC_NUM_COUNTERS >= 4
	{PAPI_L1_TCM, {DERIVED_ADD, {PNE_K8_DC_REFILL_FROM_SYSTEM_MOES,PNE_K8_DC_REFILL_FROM_L2_MOES,PNE_K8_IC_REFILL_FROM_SYSTEM,PNE_K8_IC_REFILL_FROM_L2},{0,}}},
#endif
#if HWPMC_NUM_COUNTERS >= 2
	{PAPI_L2_TCM, {DERIVED_ADD, {PNE_K8_DC_REFILL_FROM_SYSTEM_MOES,PNE_K8_IC_REFILL_FROM_SYSTEM}, {0,}}},
	{PAPI_L2_ICA, {DERIVED_ADD, {PNE_K8_IC_REFILL_FROM_SYSTEM,PNE_K8_IC_REFILL_FROM_L2}, {0,}}},
	{PAPI_L2_TCH, {DERIVED_ADD, {PNE_K8_IC_REFILL_FROM_L2,PNE_K8_DC_REFILL_FROM_L2_MOES}, {0,}}},
#endif
#if HWPMC_NUM_COUNTERS >= 4
	{PAPI_L2_TCA, {DERIVED_ADD, {PNE_K8_IC_REFILL_FROM_L2,PNE_K8_IC_REFILL_FROM_SYSTEM,PNE_K8_DC_REFILL_FROM_L2_MOES,PNE_K8_DC_REFILL_FROM_SYSTEM_MOES}, {0,}}},
#endif
	{PAPI_FML_INS, {0, {PNE_K8_FP_DISPATCHED_FPU_MULS}, {0,}}},
	{PAPI_FAD_INS, {0, {PNE_K8_FP_DISPATCHED_FPU_ADDS}, {0,}}},
	{PAPI_FP_OPS, {0, {PNE_K8_FP_DISPATCHED_FPU_ADDS_AND_MULS}, {0,}}},
	{PAPI_FP_INS, {0, {PNE_K8_FR_RETIRED_FPU_INSTRUCTIONS}, {0,}}},
	{PAPI_FPU_IDL, {0, {PNE_K8_FP_CYCLES_WITH_NO_FPU_OPS_RETIRED}, {0,}}},
	{0, {0, {PAPI_NULL}, {0,}}}
};
