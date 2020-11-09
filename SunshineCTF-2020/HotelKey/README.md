# Hotel Key

This was a easy rev challenge. First we can use ghidra to decompile the binary. We can see this function `check_flag` that have multiple if/else. This seems a job to `angr`.

```py

import angr
proj = angr.Project('hotel_key_puzzle', auto_load_libs=False)
state = proj.factory.entry_state()
simgr = proj.factory.simgr()
simgr.explore(find=lambda s: b"I see you found the key, hopefully your bags are in your room by this point." in s.posix.dumps(1))
s = simgr.found[0]
print(s.posix.dumps(0))

b'sun{b3llh0p5-runn1n6-qu1ckly}\x00\xd9\xd9\xd9\xd9\xd9\xd9\xd9\xd9\xd9\xd9\xd9\xd9\xd9\xd9\xd9\xd9\xd9\xd9\xd9\xd9\xd9\xd9\xd9\xd9\xd9\xd9\xd9\xd9\xd9\xd9'

```
