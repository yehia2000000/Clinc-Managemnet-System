#define max_size 50
struct patient 
{
	u32 name [max_size] ;
	u32 age ;
	u32 gender [max_size];
	u32 id ;
	struct patient * next ;
	
};
typedef struct patient patient ;

struct slots 
{
	u32 data_id ;
	
	struct slots * next ;
	
	
};
typedef struct slots slot ;