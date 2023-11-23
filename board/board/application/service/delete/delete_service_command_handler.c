#include <stdlib.h>
#include <stdio.h>

#include "delete_service_command_handler.h"
#include "../board_service_command.h"
#include "../../../domain/model/post_model.h"
#include "../../../../utility/file/make_file_from_format/make_file_from_format.h"

// request를 통해 호출될 함수
// mapper를 통해 table이랑 연결된다.
void post_delete()
{
    unsigned int uid = get_uid_from_input_with_message("삭제 할 게시글의 번호를 입력 해 주세요: ");

    delete_post_model_from_post_array(uid);
}
// 실제 구동 될 함수
void delete_post_model_from_post_array(unsigned int uid)
{
    unsigned int loop;
    unsigned int current_post_count = get_post_count();

    // 임시 배열을 만들고, uid에 해당되는 post_model을 제외한 나머지post_model을 넣는다.
    unsigned int tmp_post_count = 0;
    post_model **tmp_array = (post_model **)malloc(sizeof(post_model*) * (current_post_count-1));
    
    for(loop = 0; loop < current_post_count; loop ++)
    {
        if( post_model_array[loop]->unique_id == uid)
        {
         // 삭제된 post_model은 free와 ptr*=NULL을 통해서 완전 초기화시킨다.
         free(post_model_array[loop]);
         post_model_array[loop] = NULL;
         continue;
        }
      
            
        tmp_array[tmp_post_count] = post_model_array[loop];
       
        tmp_post_count++;
    }

    post_model_array = (post_model **)realloc(post_model_array, sizeof(post_model*) * (current_post_count-1));
    
    post_model_array = tmp_array;
    
    decrement_post_count();
    write_file_with_array();

}


