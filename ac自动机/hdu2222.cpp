#define LOCAL
#define MAXN 1000005
#include<bits/stdc++.h>
using namespace std;
struct node
{
    node *nxt[30];
    node *fail;
    int cnt=0;
    node()
    {
        cnt=0;
        fail=NULL;
        for(int i=0;i<29;i++) nxt[i]=NULL;
    }
} *root;
node* q[MAXN];
char str[MAXN];
char tmp[100];
void Insert()//0->root
{
    node *u=root;
    for(int i=0;tmp[i];i++)
    {
        int k=tmp[i]-'a';
        if(u->nxt[k]==NULL)
        {
            u->nxt[k]=new node();
        }
        u=u->nxt[k];
    }
    u->cnt++;
    return;
}
void bfs()
{
    int head=1,tail=1;
    q[head]=root;
    node* u;
    node* temp;
    while(head<=tail)
    {
        u=q[head];
        head++;
        for(int i=0;i<26;i++)
        {
            if(u->nxt[i])
            {
                if(u==root)
                {
                    u->nxt[i]->fail=root;
                }
                else
                {
                    temp=u->fail;
                    while(temp)
                    {
                        if(temp->nxt[i])
                        {
                            u->nxt[i]->fail=temp->nxt[i];
                            break;
                        }
                        temp=temp->fail;
                    }
                    if(!temp) u->nxt[i]->fail=root;
                }q[++tail]=u->nxt[i];
            }

        }
    }
}
void del(node *x)
{
    if(x==NULL) return ;
    for(int i=0;i<26;i++)
    {
        del(x->nxt[i]);
    }
    delete(x);
}
int qurey()
{
    int ans=0;
    node* u=root;
    node* temp;
    //cout<<"0"<<endl;
    for(int i=0;str[i];i++)
    {
    //cout<<"="<<endl;
       int k=str[i]-'a';
       while(!u->nxt[k]&&u!=root) u=u->fail;
       u=u->nxt[k];
       if(!u) u=root;
       temp=u;
       //cout<<u;
       while(temp!=root&&temp->cnt!=-1)
       {
           //cout<<"2";
           ans+=temp->cnt;
           temp->cnt=-1;
           temp=temp->fail;
       }
    }
    //cout<<"___"<<endl;
    return ans;
}
int main()
{
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    int t;
    scanf("%d",&t);
    while(t--)
    {
        root=new node();
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%s",tmp);
            Insert();
        }
        bfs();
        scanf("%s",str);
        //cout<<"#"<<endl;
        printf("%d\n",qurey());
        //cout<<"##"<<endl;
        del(root);
    }
}
