/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (C) 2015 Freescale Semiconductor, Inc.
 *
 * Author:
 *	Peng Fan <Peng.Fan@freescale.com>
 */

#ifndef _ASM_ARCH_CLOCK_H
#define _ASM_ARCH_CLOCK_H

#include <common.h>
#include <asm/arch/crm_regs.h>

#ifdef CONFIG_SYS_MX7_HCLK
#define MXC_HCLK	CONFIG_SYS_MX7_HCLK
#else
#define MXC_HCLK	24000000
#endif

#ifdef CONFIG_SYS_MX7_CLK32
#define MXC_CLK32	CONFIG_SYS_MX7_CLK32
#else
#define MXC_CLK32	32768
#endif

/* Mainly for compatible to imx common code. */
enum mxc_clock {
	MXC_ARM_CLK = 0,
	MXC_AHB_CLK,
	MXC_IPG_CLK,
	MXC_UART_CLK,
	MXC_CSPI_CLK,
	MXC_AXI_CLK,
	MXC_DDR_CLK,
	MXC_ESDHC_CLK,
	MXC_ESDHC2_CLK,
	MXC_ESDHC3_CLK,
	MXC_I2C_CLK,
};

/* PLL supported by i.mx7d */
enum pll_clocks {
	PLL_CORE,	/* Core PLL */
	PLL_SYS,	/* System PLL*/
	PLL_ENET,	/* Enet PLL */
	PLL_AUDIO,	/* Audio PLL */
	PLL_VIDEO,	/* Video PLL*/
	PLL_DDR,	/* Dram PLL */
	PLL_USB,	/* USB PLL, fixed at 480MHZ */
};

/* clk src for clock root gen */
enum clk_root_src {
	OSC_24M_CLK,

	PLL_ARM_MAIN_800M_CLK,

	PLL_SYS_MAIN_480M_CLK,
	PLL_SYS_MAIN_240M_CLK,
	PLL_SYS_MAIN_120M_CLK,
	PLL_SYS_PFD0_392M_CLK,
	PLL_SYS_PFD0_196M_CLK,
	PLL_SYS_PFD1_332M_CLK,
	PLL_SYS_PFD1_166M_CLK,
	PLL_SYS_PFD2_270M_CLK,
	PLL_SYS_PFD2_135M_CLK,
	PLL_SYS_PFD3_CLK,
	PLL_SYS_PFD4_CLK,
	PLL_SYS_PFD5_CLK,
	PLL_SYS_PFD6_CLK,
	PLL_SYS_PFD7_CLK,

	PLL_ENET_MAIN_500M_CLK,
	PLL_ENET_MAIN_250M_CLK,
	PLL_ENET_MAIN_125M_CLK,
	PLL_ENET_MAIN_100M_CLK,
	PLL_ENET_MAIN_50M_CLK,
	PLL_ENET_MAIN_40M_CLK,
	PLL_ENET_MAIN_25M_CLK,

	PLL_DRAM_MAIN_1066M_CLK,
	PLL_DRAM_MAIN_533M_CLK,

	PLL_AUDIO_MAIN_CLK,
	PLL_VIDEO_MAIN_CLK,

	PLL_USB_MAIN_480M_CLK,		/* fixed at 480MHZ */

	EXT_CLK_1,
	EXT_CLK_2,
	EXT_CLK_3,
	EXT_CLK_4,

	REF_1M_CLK,
	OSC_32K_CLK,
};

/*
 * Clock root index
 */
enum clk_root_index {
	ARM_A7_CLK_ROOT = 0,
	ARM_M4_CLK_ROOT = 1,
	ARM_M0_CLK_ROOT = 2,
	MAIN_AXI_CLK_ROOT = 16,
	DISP_AXI_CLK_ROOT = 17,
	ENET_AXI_CLK_ROOT = 18,
	NAND_USDHC_BUS_CLK_ROOT = 19,
	AHB_CLK_ROOT = 32,
	DRAM_PHYM_CLK_ROOT = 48,
	DRAM_CLK_ROOT = 49,
	DRAM_PHYM_ALT_CLK_ROOT = 64,
	DRAM_ALT_CLK_ROOT = 65,
	USB_HSIC_CLK_ROOT = 66,
	PCIE_CTRL_CLK_ROOT = 67,
	PCIE_PHY_CLK_ROOT = 68,
	EPDC_PIXEL_CLK_ROOT = 69,
	LCDIF_PIXEL_CLK_ROOT = 70,
	MIPI_DSI_EXTSER_CLK_ROOT = 71,
	MIPI_CSI_WARP_CLK_ROOT = 72,
	MIPI_DPHY_REF_CLK_ROOT = 73,
	SAI1_CLK_ROOT = 74,
	SAI2_CLK_ROOT = 75,
	SAI3_CLK_ROOT = 76,
	SPDIF_CLK_ROOT = 77,
	ENET1_REF_CLK_ROOT = 78,
	ENET1_TIME_CLK_ROOT = 79,
	ENET2_REF_CLK_ROOT = 80,
	ENET2_TIME_CLK_ROOT = 81,
	ENET_PHY_REF_CLK_ROOT = 82,
	EIM_CLK_ROOT = 83,
	NAND_CLK_ROOT = 84,
	QSPI_CLK_ROOT = 85,
	USDHC1_CLK_ROOT = 86,
	USDHC2_CLK_ROOT = 87,
	USDHC3_CLK_ROOT = 88,
	CAN1_CLK_ROOT = 89,
	CAN2_CLK_ROOT = 90,
	I2C1_CLK_ROOT = 91,
	I2C2_CLK_ROOT = 92,
	I2C3_CLK_ROOT = 93,
	I2C4_CLK_ROOT = 94,
	UART1_CLK_ROOT = 95,
	UART2_CLK_ROOT = 96,
	UART3_CLK_ROOT = 97,
	UART4_CLK_ROOT = 98,
	UART5_CLK_ROOT = 99,
	UART6_CLK_ROOT = 100,
	UART7_CLK_ROOT = 101,
	ECSPI1_CLK_ROOT = 102,
	ECSPI2_CLK_ROOT = 103,
	ECSPI3_CLK_ROOT = 104,
	ECSPI4_CLK_ROOT = 105,
	PWM1_CLK_ROOT = 106,
	PWM2_CLK_ROOT = 107,
	PWM3_CLK_ROOT = 108,
	PWM4_CLK_ROOT = 109,
	FLEXTIMER1_CLK_ROOT = 110,
	FLEXTIMER2_CLK_ROOT = 111,
	SIM1_CLK_ROOT = 112,
	SIM2_CLK_ROOT = 113,
	GPT1_CLK_ROOT = 114,
	GPT2_CLK_ROOT = 115,
	GPT3_CLK_ROOT = 116,
	GPT4_CLK_ROOT = 117,
	TRACE_CLK_ROOT = 118,
	WDOG_CLK_ROOT = 119,
	CSI_MCLK_CLK_ROOT = 120,
	AUDIO_MCLK_CLK_ROOT = 121,
	WRCLK_CLK_ROOT = 122,
	IPP_DO_CLKO1 = 123,
	IPP_DO_CLKO2 = 124,

	CLK_ROOT_MAX,
};

struct clk_root_setting {
	enum clk_root_index root;
	u32 setting;
};

/*
 * CCGR mapping
 */
enum clk_ccgr_index {
	CCGR_CPU = 0,
	CCGR_M4 = 1,
	CCGR_SIM_MAIN = 4,
	CCGR_SIM_DISPLAY = 5,
	CCGR_SIM_ENET = 6,
	CCGR_SIM_M = 7,
	CCGR_SIM_S = 8,
	CCGR_SIM_WAKEUP = 9,
	CCGR_IPMUX1 = 10,
	CCGR_IPMUX2 = 11,
	CCGR_IPMUX3 = 12,
	CCGR_ROM = 16,
	CCGR_OCRAM = 17,
	CCGR_OCRAM_S = 18,
	CCGR_DRAM = 19,
	CCGR_RAWNAND = 20,
	CCGR_QSPI = 21,
	CCGR_WEIM = 22,
	CCGR_ADC = 32,
	CCGR_ANATOP = 33,
	CCGR_SCTR = 34,
	CCGR_OCOTP = 35,
	CCGR_CAAM = 36,
	CCGR_SNVS = 37,
	CCGR_RDC = 38,
	CCGR_MU = 39,
	CCGR_HS = 40,
	CCGR_DVFS = 41,
	CCGR_QOS = 42,
	CCGR_QOS_DISPMIX = 43,
	CCGR_QOS_MEGAMIX = 44,
	CCGR_CSU = 45,
	CCGR_DBGMON = 46,
	CCGR_DEBUG = 47,
	CCGR_TRACE = 48,
	CCGR_SEC_DEBUG = 49,
	CCGR_SEMA1 = 64,
	CCGR_SEMA2 = 65,
	CCGR_PERFMON1 = 68,
	CCGR_PERFMON2 = 69,
	CCGR_SDMA = 72,
	CCGR_CSI = 73,
	CCGR_EPDC = 74,
	CCGR_LCDIF = 75,
	CCGR_PXP = 76,
	CCGR_PCIE = 96,
	CCGR_MIPI_CSI = 100,
	CCGR_MIPI_DSI = 101,
	CCGR_MIPI_MEM_PHY = 102,
	CCGR_USB_CTRL = 104,
	CCGR_USB_HSIC = 105,
	CCGR_USB_PHY1 = 106,
	CCGR_USB_PHY2 = 107,
	CCGR_USDHC1 = 108,
	CCGR_USDHC2 = 109,
	CCGR_USDHC3 = 110,
	CCGR_ENET1 = 112,
	CCGR_ENET2 = 113,
	CCGR_CAN1 = 116,
	CCGR_CAN2 = 117,
	CCGR_ECSPI1 = 120,
	CCGR_ECSPI2 = 121,
	CCGR_ECSPI3 = 122,
	CCGR_ECSPI4 = 123,
	CCGR_GPT1 = 124,
	CCGR_GPT2 = 125,
	CCGR_GPT3 = 126,
	CCGR_GPT4 = 127,
	CCGR_FTM1 = 128,
	CCGR_FTM2 = 129,
	CCGR_PWM1 = 132,
	CCGR_PWM2 = 133,
	CCGR_PWM3 = 134,
	CCGR_PWM4 = 135,
	CCGR_I2C1 = 136,
	CCGR_I2C2 = 137,
	CCGR_I2C3 = 138,
	CCGR_I2C4 = 139,
	CCGR_SAI1 = 140,
	CCGR_SAI2 = 141,
	CCGR_SAI3 = 142,
	CCGR_SIM1 = 144,
	CCGR_SIM2 = 145,
	CCGR_UART1 = 148,
	CCGR_UART2 = 149,
	CCGR_UART3 = 150,
	CCGR_UART4 = 151,
	CCGR_UART5 = 152,
	CCGR_UART6 = 153,
	CCGR_UART7 = 154,
	CCGR_WDOG1 = 156,
	CCGR_WDOG2 = 157,
	CCGR_WDOG3 = 158,
	CCGR_WDOG4 = 159,
	CCGR_GPIO1 = 160,
	CCGR_GPIO2 = 161,
	CCGR_GPIO3 = 162,
	CCGR_GPIO4 = 163,
	CCGR_GPIO5 = 164,
	CCGR_GPIO6 = 165,
	CCGR_GPIO7 = 166,
	CCGR_IOMUX = 168,
	CCGR_IOMUX_LPSR = 169,
	CCGR_KPP = 170,

	CCGR_SKIP,
	CCGR_MAX,
};

/* Clock root channel */
enum clk_root_type {
	CCM_CORE_CHANNEL,
	CCM_BUS_CHANNEL,
	CCM_AHB_CHANNEL,
	CCM_DRAM_PHYM_CHANNEL,
	CCM_DRAM_CHANNEL,
	CCM_IP_CHANNEL,
};

#include <asm/arch/clock_slice.h>

/*
 * entry: the clock root index
 * type: ccm channel
 * src_mux: each entry corresponding to the clock src, detailed info in CCM RM
 */
struct clk_root_map {
	enum clk_root_index entry;
	enum clk_root_type type;
	uint8_t src_mux[8];
};

enum enet_freq {
	ENET_25MHZ,
	ENET_50MHZ,
	ENET_125MHZ,
};

u32 get_root_clk(enum clk_root_index clock_id);
u32 mxc_get_clock(enum mxc_clock clk);
u32 imx_get_uartclk(void);
u32 imx_get_fecclk(void);
void clock_init(void);
#ifdef CONFIG_SYS_I2C_MXC
int enable_i2c_clk(unsigned char enable, unsigned i2c_num);
#endif
#ifdef CONFIG_FEC_MXC
int set_clk_enet(enum enet_freq type);
#endif
int set_clk_qspi(void);
int set_clk_nand(void);
#ifdef CONFIG_MXC_OCOTP
void enable_ocotp_clk(unsigned char enable);
#endif
void enable_usboh3_clk(unsigned char enable);
#ifdef CONFIG_SECURE_BOOT
void hab_caam_clock_enable(unsigned char enable);
#endif
int mxs_set_lcdclk(uint32_t base_addr, uint32_t freq);
void enable_thermal_clk(void);
#endif
