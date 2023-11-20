#include <stdio.h>

#include "board/application/service/delete/delete_service_command_handler.h"
#include "board/domain/model/post_model.h"

int main (void)
{
    init_post_model_object(NEW_POST,"asd","qwe","zxc","qweasdzxc");
    init_post_model_object(NEW_POST,"123","456","789","987654321");
    init_post_model_object(NEW_POST,"iop","uio","hjk","yuirtyurh");
    init_post_model_object(NEW_POST,"ddfgj","tryet","cvbm","gqwertxdgfhj");

    delete_post_model_from_post_array(2);


    
    for(unsigned int i =0; i<3; i++)
    {
        printf("%d\n",i);
        printf("uid: %d\ntitle: %s\nwriter: %s\ncontents: %s\n", 
            get_post_model_array()[i]->unique_id,get_post_model_array()[i]->title, 
            get_post_model_array()[i]->writer, get_post_model_array()[i]->content);
        printf("\n");
    }
    


    return 0;
}
