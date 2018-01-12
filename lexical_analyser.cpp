
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node {
    struct node* child[11];
    bool isleaf;
};

typedef struct node node;

node* create(){

    node* temp = new node;
    for(int i=0;i<10;i++){
        temp->child[i] = NULL;
    }
    temp->isleaf = false;
    return temp;
}

void insert(node* root, string s){
    node* temp = root;
    for(int i=0;i<s.length();i++){
        if(!temp->child[s[i]-'0'])
            temp->child[s[i]-'0']= create();
        temp = temp->child[s[i]-'0'];
        }
    temp->isleaf = true;
}

ll search(node* root , string s){
    node* temp = root;
    for(int i=0;i<s.length();i++){
    ll z = s[i]-'0';
    if(!temp->child[z])
        return -1;
    temp = temp->child[z];
    }
    return 1;
}

int main(){

    ios_base::sync_with_stdio(false);
    ll n,l,q,w;
    string s,c;
    cin>>q;

    node* root = create();
    for(int i=0;i<=32767;i++){
        stringstream ss;
        ss << i;
        string str = ss.str();
        insert(root,str);
    }
    while(q--){
        cin>>s;
        if(s == "-32768"){
            cout<<"1\n";
        }
        else if(s[0]=='-')
        {
            s=s.substr(1,s.size());
            cout<<search(root,s)<<endl;
        }
        else
            cout<<search(root,s)<<endl;
    }
    return 0;
}
