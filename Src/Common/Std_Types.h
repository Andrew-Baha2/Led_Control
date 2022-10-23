/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         \File:  std_types.h
 *
 *	\Author: Andrew Bahaa
 *
 *  \Description:  Provision of Standard Types
 *
 *********************************************************************************************************************/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Boolean Data Type */
typedef unsigned char boolean;

/* Boolean Values */
#ifndef FALSE
#define FALSE       (0u)
#endif

#ifndef TRUE
#define TRUE        (1u)
#endif

#define LOGIC_HIGH        (1u)
#define LOGIC_LOW         (0u)

#define NULL_PTR    ((void*)0)

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND POINTERS
 *********************************************************************************************************************/

typedef unsigned char         uint8;
typedef signed char           sint8;
typedef unsigned short        uint16;
typedef signed short          sint16;
typedef unsigned long         uint32;
typedef signed long           sint32;
typedef unsigned long long    uint64;
typedef signed long long      sint64;
typedef float                 float32;
typedef double                float64;

typedef unsigned char*         uint8_ptr;
typedef signed char*           sint8_ptr;
typedef unsigned short*        uint16_ptr;
typedef signed short*          sint16_ptr;
typedef unsigned long*         uint32_ptr;
typedef signed long*           sint32_ptr;
typedef unsigned long long*    uint64_ptr;
typedef signed long long*      sint64_ptr;
typedef float*                 float32_ptr;
typedef double*                float64_ptr;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
 

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* STD_TYPES_H */
/**********************************************************************************************************************
 *  END OF FILE: std_types.h
 *********************************************************************************************************************/
