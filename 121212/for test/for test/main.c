#include "includes/ft_printf.h"
#include <stdio.h>
int	main()
{
	char *str = "Hello";
	int d;	
//	d = ;
 	// printf("--%0d--\n", -42);                   
 	// // printf("--%00d--\n", -42);                  
 	// printf("--%5d--\n", 42);                      
 	// printf("--%05d--\n", 42);                     
 	printf("--%0+5d--\n", 42);                    
 	// printf("--%5d--\n", -42);                     
 	// printf("--%05d--\n", -42);                    
 	// printf("--%0+5d--\n", -42);                   
 	// printf("--%-5d--\n", 42);            

printf("\n");
	// ft_printf("--%0d--\n", -42);                   
 	// ft_printf("--%00d--\n", -42);                  
 	// ft_printf("--%5d--\n", 42);                      
 	// ft_printf("--%05d--\n", 42);                     
 	ft_printf("--%0+5d--\n", 42);                    
 	// ft_printf("--%5d--\n", -42);                     
 	// ft_printf("--%05d--\n", -42);                    
 	// ft_printf("--%0+5d--\n", -42);                   
 	// ft_printf("--%-5d--\n", 42);                                        
	return (0);
}

