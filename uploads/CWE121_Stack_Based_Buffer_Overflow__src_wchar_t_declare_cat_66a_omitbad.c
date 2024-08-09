/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_declare_cat_66a.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__src.label.xml
Template File: sources-sink-66a.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sinks: cat
 *    BadSink : Copy data to string using wcscat
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


#ifndef OMITBAD

/* bad function declaration */
void CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_declare_cat_66b_badSink(wchar_t * dataArray[]);

void CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_declare_cat_66_bad()
{
    wchar_t * data;
    wchar_t * dataArray[5];
    wchar_t dataBuffer[100];
    data = dataBuffer;
    /* FLAW: Initialize data as a large buffer that is larger than the small buffer used in the sink */
    wmemset(data, L'A', 100-1); /* fill with L'A's */
    data[100-1] = L'\0'; /* null terminate */
    /* put data in array */
    dataArray[2] = data;
    CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_declare_cat_66b_badSink(dataArray);
}

#endif