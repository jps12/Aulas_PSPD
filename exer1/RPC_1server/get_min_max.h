/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _GET_MIN_MAX_H_RPCGEN
#define _GET_MIN_MAX_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif

#define MAX_SIZE 5000

struct vetor {
	double vetor[MAX_SIZE];
};
typedef struct vetor vetor;

struct double_pair {
	double a;
	double b;
};
typedef struct double_pair double_pair;

#define MIN_MAX 200
#define VERSAO 100

#if defined(__STDC__) || defined(__cplusplus)
#define vetor_min_max 1
extern  double_pair * vetor_min_max_100(vetor *, CLIENT *);
extern  double_pair * vetor_min_max_100_svc(vetor *, struct svc_req *);
extern int min_max_100_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define vetor_min_max 1
extern  double_pair * vetor_min_max_100();
extern  double_pair * vetor_min_max_100_svc();
extern int min_max_100_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_vetor (XDR *, vetor*);
extern  bool_t xdr_double_pair (XDR *, double_pair*);

#else /* K&R C */
extern bool_t xdr_vetor ();
extern bool_t xdr_double_pair ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_GET_MIN_MAX_H_RPCGEN */
