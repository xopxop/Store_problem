#include "program.h"

static void cleanupOrder(t_order *order)
{
	if (order == NULL)
		return;
	(order->productCode) ? free(order->productCode) : 0;
	(order->batchSizeCode) ? free(order->batchSizeCode) : 0;
	(order->productName) ? free(order->productName) : 0;
	free(order);
}

void cleanupAllOrder(t_order **order)
{
	for (int i = 0; order[i]; i++)
		cleanupOrder(order[i]);
	free(order);
}

void cleanupListOfProduct(t_product **arr)
{
	for (int i = 0; arr[i]; i++)
	{
		(arr[i]->code) ? free(arr[i]->code) : 0;
		(arr[i]->name) ? free(arr[i]->name) : 0;
		free(arr[i]);
	}
}

void cleanupListOfBatchSizes(t_batchSize **arr)
{
	for (int i = 0; arr[i]; i++)
	{
		(arr[i]->code) ? free(arr[i]->code) : 0;
		free(arr[i]);
	}
}

void cleanupListOfProductBatchSize(t_productBatchSize **arr)
{
	for (int i = 0; arr[i]; i++)
	{
		(arr[i]->productCode) ? free(arr[i]->productCode) : 0;
		(arr[i]->batchSizeCode) ? free(arr[i]->batchSizeCode) : 0;
		free(arr[i]);
	}
}

void cleanupListOfBatchQuantity(t_batchQuantity **arr)
{
	for (int i = 0; arr[i]; i++)
	{
		(arr[i]->productCode) ? free(arr[i]->productCode) : 0;
		free(arr[i]);
	}
		
}
