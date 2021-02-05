#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_product
{
	char		*code;
	char		*name;
	float		price;
}				t_product;

typedef struct		s_batchSize
{
	char			*code;
	unsigned int	size;
}					t_batchSize;

typedef struct		s_productBatchSize
{
	char			*productCode;
	char			*batchSizeCode;
}					t_productBatchSize;

typedef struct		s_batchQuantity
{
	char			*productCode;
	unsigned int	quantity;
}					t_batchQuantity;

typedef struct		s_order
{
	char			*productCode;
	char			*batchSizeCode;
	char			*productName;
	unsigned int	batchSize;
	unsigned int	batchQuantity;
	float			price;	
}					t_order;

#endif
