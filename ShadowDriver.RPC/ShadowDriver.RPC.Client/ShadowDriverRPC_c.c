

/* this ALWAYS GENERATED file contains the RPC client stubs */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for .\ShadowDriverRPC.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#if defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/

#include <string.h>

#include "../ShadowDriver.RPC.Common/ShadowDriverRPC.h"

#define TYPE_FORMAT_STRING_SIZE   7                                 
#define PROC_FORMAT_STRING_SIZE   85                                
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   0            

typedef struct _ShadowDriverRPC_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } ShadowDriverRPC_MIDL_TYPE_FORMAT_STRING;

typedef struct _ShadowDriverRPC_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } ShadowDriverRPC_MIDL_PROC_FORMAT_STRING;

typedef struct _ShadowDriverRPC_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } ShadowDriverRPC_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const ShadowDriverRPC_MIDL_TYPE_FORMAT_STRING ShadowDriverRPC__MIDL_TypeFormatString;
extern const ShadowDriverRPC_MIDL_PROC_FORMAT_STRING ShadowDriverRPC__MIDL_ProcFormatString;
extern const ShadowDriverRPC_MIDL_EXPR_FORMAT_STRING ShadowDriverRPC__MIDL_ExprFormatString;

#define GENERIC_BINDING_TABLE_SIZE   0            


/* Standard interface: ShadowDriverRPC, ver. 1.0,
   GUID={0x3f299c8f,0x35db,0x46b2,{0x9d,0xef,0x6a,0x49,0xe3,0x39,0xf6,0xff}} */

handle_t ShadowDriverRPC_IfHandle;


static const RPC_CLIENT_INTERFACE ShadowDriverRPC___RpcClientInterface =
    {
    sizeof(RPC_CLIENT_INTERFACE),
    {{0x3f299c8f,0x35db,0x46b2,{0x9d,0xef,0x6a,0x49,0xe3,0x39,0xf6,0xff}},{1,0}},
    {{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}},
    0,
    0,
    0,
    0,
    0,
    0x00000000
    };
RPC_IF_HANDLE ShadowDriverRPC_v1_0_c_ifspec = (RPC_IF_HANDLE)& ShadowDriverRPC___RpcClientInterface;

extern const MIDL_STUB_DESC ShadowDriverRPC_StubDesc;

static RPC_BINDING_HANDLE ShadowDriverRPC__MIDL_AutoBindHandle;


void RPCTest( 
    /* [string][in] */ unsigned char *pszString)
{

    NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&ShadowDriverRPC_StubDesc,
                  (PFORMAT_STRING) &ShadowDriverRPC__MIDL_ProcFormatString.Format[0],
                  pszString);
    
}


void GetShadowDriverVersion( void)
{

    NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&ShadowDriverRPC_StubDesc,
                  (PFORMAT_STRING) &ShadowDriverRPC__MIDL_ProcFormatString.Format[32],
                  0);
    
}


void Shutdown( void)
{

    NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&ShadowDriverRPC_StubDesc,
                  (PFORMAT_STRING) &ShadowDriverRPC__MIDL_ProcFormatString.Format[58],
                  0);
    
}


#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif

static const ShadowDriverRPC_MIDL_PROC_FORMAT_STRING ShadowDriverRPC__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure RPCTest */

			0x32,		/* FC_BIND_PRIMITIVE */
			0x48,		/* Old Flags:  */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x0 ),	/* 0 */
/*  8 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x0 ),	/* 0 */
/* 14 */	0x42,		/* Oi2 Flags:  clt must size, has ext, */
			0x1,		/* 1 */
/* 16 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */
/* 24 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pszString */

/* 26 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 28 */	NdrFcShort( 0x0 ),	/* X64 Stack size/offset = 0 */
/* 30 */	NdrFcShort( 0x4 ),	/* Type Offset=4 */

	/* Procedure GetShadowDriverVersion */

/* 32 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x48,		/* Old Flags:  */
/* 34 */	NdrFcLong( 0x0 ),	/* 0 */
/* 38 */	NdrFcShort( 0x1 ),	/* 1 */
/* 40 */	NdrFcShort( 0x0 ),	/* X64 Stack size/offset = 0 */
/* 42 */	NdrFcShort( 0x0 ),	/* 0 */
/* 44 */	NdrFcShort( 0x0 ),	/* 0 */
/* 46 */	0x40,		/* Oi2 Flags:  has ext, */
			0x0,		/* 0 */
/* 48 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 50 */	NdrFcShort( 0x0 ),	/* 0 */
/* 52 */	NdrFcShort( 0x0 ),	/* 0 */
/* 54 */	NdrFcShort( 0x0 ),	/* 0 */
/* 56 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Procedure Shutdown */

/* 58 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x48,		/* Old Flags:  */
/* 60 */	NdrFcLong( 0x0 ),	/* 0 */
/* 64 */	NdrFcShort( 0x2 ),	/* 2 */
/* 66 */	NdrFcShort( 0x0 ),	/* X64 Stack size/offset = 0 */
/* 68 */	NdrFcShort( 0x0 ),	/* 0 */
/* 70 */	NdrFcShort( 0x0 ),	/* 0 */
/* 72 */	0x40,		/* Oi2 Flags:  has ext, */
			0x0,		/* 0 */
/* 74 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 76 */	NdrFcShort( 0x0 ),	/* 0 */
/* 78 */	NdrFcShort( 0x0 ),	/* 0 */
/* 80 */	NdrFcShort( 0x0 ),	/* 0 */
/* 82 */	NdrFcShort( 0x0 ),	/* 0 */

			0x0
        }
    };

static const ShadowDriverRPC_MIDL_TYPE_FORMAT_STRING ShadowDriverRPC__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/*  4 */	
			0x22,		/* FC_C_CSTRING */
			0x5c,		/* FC_PAD */

			0x0
        }
    };

static const unsigned short ShadowDriverRPC_FormatStringOffsetTable[] =
    {
    0,
    32,
    58
    };


static const MIDL_STUB_DESC ShadowDriverRPC_StubDesc = 
    {
    (void *)& ShadowDriverRPC___RpcClientInterface,
    MIDL_user_allocate,
    MIDL_user_free,
    &ShadowDriverRPC_IfHandle,
    0,
    0,
    0,
    0,
    ShadowDriverRPC__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x801026e, /* MIDL Version 8.1.622 */
    0,
    0,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* defined(_M_AMD64)*/

