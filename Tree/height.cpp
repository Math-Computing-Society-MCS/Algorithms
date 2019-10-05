int height(Node *node)
{
    //Change the name of the node as per the driver program
    
    if (node == NULL)  
        return 0;  
    else
    {  
        int lheight = height(node->left);  
        int rheight = height(node->right);  
      
        return max(lheight,rheight)+1;  
    }  
}
