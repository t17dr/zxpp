# ZXPP: ZX Spectrum 48k emulator

This is my first emulator project, still work in progress.
The original Sinclair ROM is currently partially working, some of the games that
were distributed as ROMs and used keyboard input are playable.
Contention is currently not yet simulated.

## Current features:
- Complete instruction set
- OpenGL display without border
- Virtual keyboard
- Very simple "debugger"
- ROM image loading

## Missing features:
- Display border
- Memory and I/O contention
- Casette emulation / loading
- Input besides the keyboard

and more.

# Screenshots
![Simple debugger, Dear ImGui memory editor](https://raw.githubusercontent.com/t17dr/zxpp/master/img/screen_debugger.png)
![Virtual keyboard](https://raw.githubusercontent.com/t17dr/zxpp/master/img/screen_keyboard.png)
![Playable ROM game](https://raw.githubusercontent.com/t17dr/zxpp/master/img/screen_asteroids.png)
![Playable ROM game](https://raw.githubusercontent.com/t17dr/zxpp/master/img/screen_invaders.png)
![Playable ROM game](https://raw.githubusercontent.com/t17dr/zxpp/master/img/screen_deathstar.png)

# Links & references

## General emulator development

- [https://www.reddit.com/r/EmuDev/](https://www.reddit.com/r/EmuDev/) Emudev subreddit

## Official manuals

- [http://www.z80.info/zip/z80cpu_um.pdf](http://www.z80.info/zip/z80cpu_um.pdf) Z80 manual
- [http://zxspectrum.it.omegahg.com/doc/48ksm.pdf](http://zxspectrum.it.omegahg.com/doc/48ksm.pdf), [https://wos.meulie.net/pub/sinclair/technical-docs/ZXSpectrum48K_ServiceManual.pdf](https://wos.meulie.net/pub/sinclair/technical-docs/ZXSpectrum48K_ServiceManual.pdf) Spectrum service manual

## Documentation

- [http://datasheets.chipdb.org/Zilog/Z80/z80-documented-0.90.pdf](http://datasheets.chipdb.org/Zilog/Z80/z80-documented-0.90.pdf) Undocumented Z80 features
- [http://faqwiki.zxnet.co.uk/wiki/Z80](http://faqwiki.zxnet.co.uk/wiki/Z80) Z80 FAQ
- [http://www.primrosebank.net/computers/zxspectrum/docs/CompleteSpectrumROMDisassemblyThe.pdf](http://www.primrosebank.net/computers/zxspectrum/docs/CompleteSpectrumROMDisassemblyThe.pdf) The Complete Spectrum ROM Disassembly
- [http://www.zxdesign.info](http://www.zxdesign.info/) The Harlequin clone blog, also useful book on the ULA
- [http://worldofspectrum.org/faq/reference/z80format.htm](http://worldofspectrum.org/faq/reference/z80format.htm) Z80 snapshot format specification
- [http://scratchpad.wikia.com/wiki/Contended_IO](http://scratchpad.wikia.com/wiki/Contended_IO) Contended I/O
- [http://www.zxdesign.info/memContRevision.shtml](http://www.zxdesign.info/memContRevision.shtml) Memory contention
- [http://forums.bannister.org/ubbthreads.php?ubb=showflat&Number=96960](http://forums.bannister.org/ubbthreads.php?ubb=showflat&Number=96960) Memory contention explained
- [http://scratchpad.wikia.com/wiki/Contended_memory](http://scratchpad.wikia.com/wiki/Contended_memory) Contended memory
- [http://ramsoft.bbk.org.omegahg.com/floatingbus.html](http://ramsoft.bbk.org.omegahg.com/floatingbus.html) Floating bus/contended memory, snow effect
- [http://www.worldofspectrum.org/faq/reference/48kreference.htm](http://www.worldofspectrum.org/faq/reference/48kreference.htm) FAQ reference
- [https://fms.komkon.org/stuff/spectrum.faq](https://fms.komkon.org/stuff/spectrum.faq) Overview of timing, I/O ports and more

## Other emulators

- [https://sourceforge.net/projects/libz80/?source=typ_redirect](https://sourceforge.net/projects/libz80/?source=typ_redirect)
- [http://fuse-emulator.sourceforge.net](http://fuse-emulator.sourceforge.net/) FUSE emulator

## Articles

- [https://floooh.github.io/2016/07/12/z80-rust-ms1.html](https://floooh.github.io/2016/07/12/z80-rust-ms1.html) Z80 emulation in rust, ZEXDOC and ZEXALL tests explained

## Tests

- [http://wizard.ae.krakow.pl/~jb/qaop/tests.html](http://wizard.ae.krakow.pl/~jb/qaop/tests.html) Timing test tapes
- [http://mdfs.net/Software/Z80/Exerciser/](http://mdfs.net/Software/Z80/Exerciser/) ZEXDOC, ZEXALL

## ZX Spectrum development

- [https://github.com/z88dk](https://github.com/z88dk) Development kit - C compiler, assembler, linker
- [https://www.z88dk.org/forum/](https://www.z88dk.org/forum/) Official website of the above
- [https://github.com/juhovh/spectrum](https://github.com/juhovh/spectrum) Programming tutorial, utilities

## ROMs, tapes, game recordings

- [http://www.rzxarchive.co.uk/](http://www.rzxarchive.co.uk/) Game recordings
- [http://www.the-tipshop.co.uk/](http://www.the-tipshop.co.uk/)

## User guides

- [http://www.retroisle.com/sinclair/zxspectrum/howtouse.php](http://www.retroisle.com/sinclair/zxspectrum/howtouse.php)
- [https://www.youtube.com/watch?v=zOpittnwNP8](https://www.youtube.com/watch?v=zOpittnwNP8) 1983 ZX Spectrum programming course
- [http://www.worldofspectrum.org/ZXBasicManual/](http://www.worldofspectrum.org/ZXBasicManual/) ZX BASIC manual