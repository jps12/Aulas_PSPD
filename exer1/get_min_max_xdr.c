/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "get_min_max.h"

bool_t
xdr_vetor (XDR *xdrs, vetor *objp)
{
	register int32_t *buf;

	int i;

	if (xdrs->x_op == XDR_ENCODE) {
		buf = XDR_INLINE (xdrs, ( 100 ) * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_vector (xdrs, (char *)objp->vetor, 100,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
		} else {
			{
				register int *genp;

				for (i = 0, genp = objp->vetor;
					i < 100; ++i) {
					IXDR_PUT_LONG(buf, *genp++);
				}
			}
		}
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		buf = XDR_INLINE (xdrs, ( 100 ) * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_vector (xdrs, (char *)objp->vetor, 100,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
		} else {
			{
				register int *genp;

				for (i = 0, genp = objp->vetor;
					i < 100; ++i) {
					*genp++ = IXDR_GET_LONG(buf);
				}
			}
		}
	 return TRUE;
	}

	 if (!xdr_vector (xdrs, (char *)objp->vetor, 100,
		sizeof (int), (xdrproc_t) xdr_int))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_int_pair (XDR *xdrs, int_pair *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->a))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->b))
		 return FALSE;
	return TRUE;
}
