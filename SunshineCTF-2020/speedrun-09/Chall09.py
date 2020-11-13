#!/usr/bin/env python
# coding: utf-8

# In[1]:


import angr


# In[2]:


proj = angr.Project('chall_09', auto_load_libs=False)


# In[3]:


state = proj.factory.entry_state()
simgr = proj.factory.simgr()


# In[4]:


simgr.explore()


# In[5]:


for s in simgr.deadended:
    print(s.posix.dumps(0))


# In[ ]:




