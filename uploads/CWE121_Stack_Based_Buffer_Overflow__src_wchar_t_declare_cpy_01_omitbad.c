/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_declare_cpy_01.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__src.label.xml
Template File: sources-sink-01.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sink: cpy
 *    BadSink : Copy data to string using wcscpy
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


#ifndef OMITBAD

void CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_declare_cpy_01_bad()
{
    wchar_t * data;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    /* FLAW: Initialize data as a large buffer that is larger than the small buffer used in the sink */
    wmemset(data, L'A', 100-1); /* fill with L'A's */
    data[100-1] = L'\0'; /* null terminate */
    {
        wchar_t dest[50] = L"";
        /* POTENTIAL FLAW: Possible buffer overflow if data is larger than dest */
        wcscpy(dest, data);
        printWLine(data);
    }
}

#endif