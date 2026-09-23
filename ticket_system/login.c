//登录ID PASSWORD 
bool login( userList* head,
            userType* type,
            const char* userID,
            const char* password)
{
if (head==NULL||userID==NULL||password==NULL) 
    return false;

while(head!=NULL)
{
    if( strcmp(userID,head->user_info.userID)==0
        &&strcmp(head->user_info.userPassword,password)==0){
            *type = head->user_info.user_type;
            return true;
        }
    head=head->next_user_list;
}
return false;
}