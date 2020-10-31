#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node*right;
    node(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
node *build_tree(int *in,int *pre,int s,int e)
{
static int i=0;
if(s>e)
{
return NULL;
}

node *root=new node(pre[i]);
int index=-1;
for(int j=s;j<=e;j++)
{
if(in[j]==pre[i])
{
index=j;
break;
}
}
i++;
root->left=build_tree(in,pre,s,index-1);
root->right=build_tree(in,pre,index+1,e);
return root;

}
node * binary_tree()
{
int d;
cin>>d;

if(d==-1)
return NULL;
node *root=new node(d);
root->left=binary_tree();
root->right=binary_tree();
return root;
}
void bfs(node *root)
{
    if(root==NULL)
        return;
    queue<node *>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node *p=q.front();

        if(p==NULL)
           {  cout<<"\n";
              q.pop();
             if(!q.empty())
            q.push(NULL);
           }
           else{
            cout<<p->data<<" ";
             q.pop();

              if(p->left)
               {
               q.push(p->left);

                }
                 if(p->right)
                   {
                    q.push(p->right);

                      }
                   }
               }

}
int main()
{
//node *root=binary_tree();
int n;
cin>>n;
int in[n],pre[n];
for(int i=0;i<n;i++)
{
cin>>pre[i];
}
for(int j=0;j<n;j++)
{
cin>>in[j];
}
node *root=build_tree(in,pre,0,n-1);
bfs(root);
return 0;
}
