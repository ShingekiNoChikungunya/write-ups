Info: Since the 2 challenges used the same memory dump, and the solutions are not too big, I'll put them together.

# Drawing on the walls
Points: **100 Points**

It was given to us the following file:
```
memory.dmp: MS Windows 64bit crash dump, full dump, 524288 pages
```

Using [volatility](https://github.com/volatilityfoundation/volatility) with any windows profile we can list all the running process of the machine. 
```
vol.py -f memory.dmp --profile=Win7SP1x64 pslist
```
These process draw my attention to them `firefox.exe`, `paint.exe` and `notepad++.exe`.

Now we can extract the dump of the process using:
```
vol.py -f memory.dmp --profile=Win7SP1x64 memdump -p 2836 -D outputfolder/
```
 `p` is the process PID
 
 As an initial analysis I always use the good and old `strings`
 ```
 strings -n 16 2836.dmp | less
 ```
 
 After 1min reading the strings we found the flag: `g00dj0b_y0u_f1n411y_g07_7h3_wh0l3_fl4g`
 This was not the intended way, probably the intended way was in paint.exe that I not even touched,  and my guess is: the flag was pasted in this notepad++ and sticked to the `undo stack`. The solution to `Letter_from_the_madhouse` continue from here
 
 # Letter from the madhouse
 
 Reading the dump of notepad++.exe with:
  ```
 strings -n 16 2836.dmp | less
 ```
 We can found a `GPG Key` and a strange link `https://pastebin.com/QRzneSW7`. The link contains a `base64` text.
 
 We can decode the base64 text and output to a file using:
 ```
 cat text | base64 -d > flag.enc
```
And decode the text with the GPG Priv Key found in the texts:
```
gpg  --import privkey
gpg --output secret --decrypt flag.enc
```
Inside some big text we can read in plain text the entire flag:`Aero{d46821ea020c13a9a42e16b03d9dcccc97e1d7fa16c8673a4ebde8597715967a}`

