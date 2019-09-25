#include "btNode.h"

void dumpToArrayInOrder(btNode* bst_root, int* dumpArray)
{
   if (bst_root == 0) return;
   int dumpIndex = 0;
   dumpToArrayInOrderAux(bst_root, dumpArray, dumpIndex);
}

void dumpToArrayInOrderAux(btNode* bst_root, int* dumpArray, int& dumpIndex)
{
   if (bst_root == 0) return;
   dumpToArrayInOrderAux(bst_root->left, dumpArray, dumpIndex);
   dumpArray[dumpIndex++] = bst_root->data;
   dumpToArrayInOrderAux(bst_root->right, dumpArray, dumpIndex);
}

void tree_clear(btNode*& root)
{
   if (root == 0) return;
   tree_clear(root->left);
   tree_clear(root->right);
   delete root;
   root = 0;
}

int bst_size(btNode* bst_root)
{
   if (bst_root == 0) return 0;
   return 1 + bst_size(bst_root->left) + bst_size(bst_root->right);
}

void bst_insert(btNode*& bst_root, int insInt)
{
	//if tree is empty
   if(bst_root == 0)
   {
      btNode *temp = new btNode;
	  temp->data = insInt;
	  temp->left = 0;
	  temp->right = 0;
	  bst_root = temp;   	
   }
   
   //if root is equal to the value
   else if(bst_root->data == insInt)
      bst_root->data = insInt;
   
   else
   {
      btNode *temp = bst_root;
      while(true)
      {

         if(temp->data == insInt)
	     {
	        temp->data = insInt;
		    break;	
	     }
	  
	     else if(temp->data < insInt)
		 {
		 	//if is leaf
		    if(temp->right == 0)
			{
			   btNode *toInsert = new btNode;
               toInsert ->left = 0;
               toInsert ->right = 0;
               toInsert ->data = insInt;
               temp->right = toInsert;
               break;	
			}
			
			//if next node is not a leaf
			temp = temp->right;	
		 }
		   
	     else
	     {
            if(temp->left == 0)
            {
               btNode *toInsert = new btNode;
               toInsert->left = 0;
               toInsert->right = 0;
               toInsert->data = insInt;
               temp->left = toInsert;
               break;
            }
            temp = temp->left;	
	     }	
      } 	
   }   	
  	
}

bool bst_remove(btNode*& bst_root, int remInt)
{
   //if not in tree
   if(bst_root == 0)
      return false;
   
   //if target found
   if(bst_root->data == remInt)
   {
      //if is a leaf
	  if(bst_root->right == 0 and bst_root->left == 0)
	  {
	     delete bst_root;
		 bst_root = 0;	
	  }	
	  
	  //if has only one child node
	  else if(bst_root->right != 0 and bst_root->left == 0)
	  {
	     btNode *temp = bst_root;
		 bst_root = bst_root->right;
		 delete temp;	
	  }
	  else if(bst_root->right == 0 and bst_root->left != 0)
	  {
	     btNode *temp = bst_root;
		 bst_root = bst_root->left;
		 delete temp;	
	  }
	  
	  //if has 2 child nodes
	  else
	     bst_remove_max(bst_root->left, bst_root->data);
	  
	  return true;
   }
   
   else if(bst_root->data < remInt)
      return bst_remove(bst_root->right, remInt);
   else
      return bst_remove(bst_root->left, remInt);
}


void bst_remove_max(btNode*& bst_root, int& toRemove)
{
    //base case
   if(bst_root->right == 0) 
   {
      toRemove = bst_root->data;
      btNode *temp = bst_root;
      bst_root = bst_root->left;
      delete temp;
      return;
   }
   
   bst_remove_max(bst_root->right, toRemove);    
}

