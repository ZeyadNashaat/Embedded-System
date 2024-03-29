//*****************************************************************************
//
// pmm.h - Driver for the PMM Module.
//
//*****************************************************************************

#ifndef __MSP430WARE_PMM_H__
#define __MSP430WARE_PMM_H__

#include <driverlib/inc/hw_memmap.h>

#ifdef __MSP430_HAS_PMM__

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
// The following are values that can be passed to the voltageMonitorLevel
// parameter for functions: PMM_setupVoltageMonitor().
//
//*****************************************************************************
#define PMM_DISABLE_VMON                                            (VMONLVL_0)
#define PMM_DVCC_2350MV                                             (VMONLVL_1)
#define PMM_DVCC_2650MV                                             (VMONLVL_2)
#define PMM_DVCC_2850MV                                             (VMONLVL_3)
#define PMM_VMONIN_1160MV                                           (VMONLVL_7)

//*****************************************************************************
//
// The following are values that can be passed to the status parameter for
// functions: PMM_setRegulatorStatus().
//
//*****************************************************************************
#define PMM_REGULATOR_ON                                                 (0x00)
#define PMM_REGULATOR_OFF                                             PMMREGOFF

//*****************************************************************************
//
// The following are values that can be passed to the mask parameter for
// functions: PMM_enableInterrupt(), PMM_disableInterrupt(),
// PMM_getInterruptStatus(), and PMM_clearInterrupt() as well as returned by
// the PMM_getInterruptStatus() function.
//
//*****************************************************************************
#define PMM_VMON_INTERRUPT                                               VMONIE
#define PMM_LPM45_INTERRUPT                                            LPM45IFG

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************

//*****************************************************************************
//
//! \brief Sets up the voltage monitor.
//!
//! \param voltageMonitorLevel
//!        Valid values are:
//!        - \b PMM_DISABLE_VMON - Disable the voltage monitor
//!        - \b PMM_DVCC_2350MV - Compare DVCC to 2350mV
//!        - \b PMM_DVCC_2650MV - Compare DVCC to 2650mV
//!        - \b PMM_DVCC_2850MV - Compare DVCC to 2850mV
//!        - \b PMM_VMONIN_1160MV - Compare VMONIN to 1160mV
//!        \n Modified bits are \b VMONLVLx of \b VMONCTL register.
//!
//! Modified bits of \b VMONCTL register.
//!
//! \return None
//
//*****************************************************************************
extern void PMM_setupVoltageMonitor(uint8_t voltageMonitorLevel);

//*****************************************************************************
//
//! \brief Setup the calibration.
//!
//!
//! Modified bits of \b REFCAL0 register and bits of \b REFCAL1 register.
//!
//! \return None
//
//*****************************************************************************
extern void PMM_calibrateReference(void);

//*****************************************************************************
//
//! \brief Set the status of the PMM regulator
//!
//! \param status
//!        Valid values are:
//!        - \b PMM_REGULATOR_ON - Turn the PMM regulator off
//!        - \b PMM_REGULATOR_OFF - Turn the PMM regulator on
//!        \n Modified bits are \b REGOFF of \b LPM45CTL register.
//!
//! Modified bits of \b LPM45CTL register.
//!
//! \return None
//
//*****************************************************************************
extern void PMM_setRegulatorStatus(uint8_t status);

//*****************************************************************************
//
//! \brief Unlocks the IO
//!
//!
//! Modified bits are \b LOCKLPM45 of \b LPM45CTL register.
//!
//! \return None
//
//*****************************************************************************
extern void PMM_unlockIOConfiguration(void);

//*****************************************************************************
//
//! \brief Enables interrupts
//!
//! \param mask
//!        Mask value is the logical OR of any of the following:
//!        - \b PMM_VMON_INTERRUPT - Voltage Monitor Interrupt
//!
//! \return None
//
//*****************************************************************************
extern void PMM_enableInterrupt(uint8_t mask);

//*****************************************************************************
//
//! \brief Disables interrupts
//!
//! \param mask
//!        Mask value is the logical OR of any of the following:
//!        - \b PMM_VMON_INTERRUPT - Voltage Monitor Interrupt
//!
//! \return None
//
//*****************************************************************************
extern void PMM_disableInterrupt(uint8_t mask);

//*****************************************************************************
//
//! \brief Returns the interrupt status
//!
//! \param mask
//!        Mask value is the logical OR of any of the following:
//!        - \b PMM_VMON_INTERRUPT - Voltage Monitor Interrupt
//!        - \b PMM_LPM45_INTERRUPT - LPM 4.5 Interrupt
//!
//! \return Logical OR of any of the following:
//!         - \b PMM_VMON_INTERRUPT Voltage Monitor Interrupt
//!         - \b PMM_LPM45_INTERRUPT LPM 4.5 Interrupt
//!         \n indicating the status of the masked interrupts
//
//*****************************************************************************
extern uint8_t PMM_getInterruptStatus(uint8_t mask);

//*****************************************************************************
//
//! \brief Clears the masked interrupts
//!
//! \param mask
//!        Mask value is the logical OR of any of the following:
//!        - \b PMM_LPM45_INTERRUPT - LPM 4.5 Interrupt
//!
//! \return None
//
//*****************************************************************************
extern void PMM_clearInterrupt(uint8_t mask);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif
#endif // __MSP430WARE_PMM_H__
