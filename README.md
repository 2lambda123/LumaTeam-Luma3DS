# SaltFW

Slim Alternative Firmware for 3DS!  
### Features: 
- No payload support.
- No config, perfect for minimalists and children.
- No EmuNAND.
- Arm9loaderhax only.
- Automatic firmware patching.
- Automatic TWL/AGB patching.
- Automatic region-free patching.
- Automatic reboot patching.
- Optional splash screen. _(Not available in SaltLite.)_
- Optional region/language patching. _(Not available in SaltLite.)_
- Optional firmware.bin for NTR. _(Not available in SaltLite.)_
- **Install and forget.**

### How to install:
1. Drop `SaltFW.bin` or `SaltLite.bin` to the root of your SD.
2. Set your choice of bootmanager to load `/SaltFW.bin`/`/SaltLite.bin` **OR** use `arm9loaderhax.bin`.
3. DONE!

### How to use splash/bootlogo
_(Not available in SaltLite.)_  

1. Create `SaltFW` folder to the root of your SD.
2. Put `splash.bin` **OR** `splashbottom.bin` **OR** both in `SaltFW` folder
3. DONE!

### How to use NTR CFW
_(Not available in SaltLite.)_  

1. Download [this](http://www70.zippyshare.com/v/Fbj6n1vB/file.html).
2. Put `firmware.bin` from the folder for your device, to the root of SD.
3. Install NTR CFW like regular.
4. DONE!

### How to use Region/Language emulation
_(Not available in SaltLite.)_  

1. Create `SaltFW` folder in the root of your SD.
2. Create `locales` folder in `SaltFW`.
3. Create a `txt` file titleID of the game you want to edit. (e.g. `0004000000055E00.txt`)
4. Inside the file, put `RGN LN` where RGN is the region code, and LN is the language code. (e.g. `JPN JP`)
5. DONE!

### Compiling
You'll need armips, [bin2c](https://sourceforge.net/projects/bin2c/), and a recent build of [makerom](https://github.com/profi200/Project_CTR) added to your PATH. [HERE](http://www91.zippyshare.com/v/ePGpjk9r/file.html) is a pre-compiled version of armips for Windows.  
Then, just run "make" and everything should work!  
You can find the compiled files in the 'out' folder.


### Credits
AuroraWright for her great coding.  
Rei for his great ReiNand.  
And everyone they mentioned in their credits sections.  
Thanks, all of you.

### License
See `LICENSE.txt`
