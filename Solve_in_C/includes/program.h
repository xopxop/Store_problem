#ifndef PROGRAM_H
# define PROGRAM_H
#include "struct.h"
#include "struct.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

# define DEFAULT_SIZE 1
# define DEFAULT_QUANTITY 1
# define DEFAULT_STRING "BS_GENERATED_"

t_product			**initProducts(void);
t_batchSize			**initBatchSizes(void);
t_productBatchSize	**initProductBatchSize(void);
t_batchQuantity		**initBatchQuantity(void);
void				cleanupAllOrder(t_order **order);
void				cleanupListOfProduct(t_product **arr);
void				cleanupListOfBatchSizes(t_batchSize **arr);
void 				cleanupListOfProductBatchSize(t_productBatchSize **arr);
void 				cleanupListOfBatchQuantity(t_batchQuantity **arr);
t_order				**solution(t_product **listOfProduct, t_batchSize **listOfBatchSizes, t_productBatchSize **listOfProductBatchSize, t_batchQuantity **listOfBatchQuantity, bool batchSizeSelection);

#endif
