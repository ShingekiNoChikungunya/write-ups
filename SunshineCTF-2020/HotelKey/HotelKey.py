#!/usr/bin/env python
# coding: utf-8

# In[1]:


import angr


# In[3]:


proj = angr.Project('hotel_key_puzzle', auto_load_libs=False)


# In[5]:


state = proj.factory.entry_state()
simgr = proj.factory.simgr()


# In[7]:


simgr.explore(find=lambda s: b"I see you found the key, hopefully your bags are in your room by this point." in s.posix.dumps(1))


# In[8]:


s = simgr.found[0]


# In[9]:

print(s.posix.dumps(0))


# In[ ]:




