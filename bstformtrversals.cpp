Node<T>* arraysToBST(vector<int>& preorder,vector<int>& inorder)
   {
   	    if(inorder.empty() || preorder.empty())
   	   {
   	   	  return nullptr;	  	
	   }
	   
	   int count=0;
	   
	   Node<T>* root=new Node<T>(preorder[0]);
	   
	   while(inorder[count]!=root->data)
	   {
	   	count++;
	   }
	   
	   vector<int>inleft(inorder.begin(),inorder.begin()+count);
	   vector<int>inright(inorder.begin()+count+1,inorder.end());
	   vector<int>preleft(preorder.begin()+1,preorder.begin()+1+count);
	   vector<int>preright(preorder.begin()+count+1, preorder.end());
	   
	   root->left=arraysToBST(preleft,inleft);
	   root->right=arraysToBST(preright,inright);
	   
	   return root;
   }
