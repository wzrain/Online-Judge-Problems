#include <iostream>
#include <string>

using namespace std;

string scpt[100000];

int main()
{
    string txt;int top=0;
    bool flag=true;
    while(true){
        if(!(cin>>txt))break;
        if(txt=="begin"){
            if(top==0){
                scpt[top]=txt;
                top++;
                continue;
            }
            else if(scpt[top-1]=="if"){
                flag=false;
                break;
            }
            else {
                scpt[top]=txt;top++;
                continue;
            }
        }
        if(txt=="if"){
            scpt[top]=txt;top++;
            continue;
        }
        if(txt=="then"){
            if(top==0){
                flag=false;
                break;
            }
            else if(scpt[top-1]=="if"){
                scpt[top]=txt;
                top++;
                continue;
            }
            else{
                flag=false;
                break;
            }
        }
        if(txt=="else"){
            if(top<=0){flag=false;break;}
            else if(scpt[top-1]=="then"){
                top-=2;
                continue;
            }
            else{
                flag=false;
                break;
            }
        }
        if(txt=="end"){
            if(top<=0){flag=false;break;}
            if(scpt[top-1]=="begin"){
                top--;continue;
            }
            else if(scpt[top-1]=="then"){
                while(top>0&&scpt[top-1]=="then")top-=2;
                if(top<=0){
                    flag=false;
                    break;
                }
                else if(scpt[top-1]=="begin"){
                    top--;continue;
                }
            }
            else{
                flag=false;
                break;
            }
        }
    }
    if(flag&&top==0)cout<<"Match!";
    else cout<<"Error!";
    return 0;
}
