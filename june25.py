class Solution(object):
    def inorder(self,root,x):
        if root !=None:
            self.inorder(root.left,x)
            x.append(root.val)
            self.inorder(root.right,x)
    def change(self,root,suf):
        if root !=None:
            self.change(root.left,suf)
            root.val=root.val+suf[root.val]
            self.change(root.right,suf)
    def bstToGst(self, root):
        x=[]
        self.inorder(root,x)
        n=len(x)
        suf=[None]*100
        suf[x[n-1]]=0
        for i in range(1,n):
            suf[x[n-1-i]]=suf[x[n-i]]+x[n-i]
        self.change(root,suf)
        return root
        