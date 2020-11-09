typedef unsigned char   undefined;

typedef unsigned char    byte;
typedef unsigned char    dwfenc;
typedef unsigned int    dword;
typedef unsigned long    qword;
typedef unsigned long    ulong;
typedef unsigned char    undefined1;
typedef unsigned int    undefined4;
typedef unsigned long    undefined8;
typedef unsigned short    word;
typedef struct eh_frame_hdr eh_frame_hdr, *Peh_frame_hdr;

struct eh_frame_hdr {
    byte eh_frame_hdr_version; // Exception Handler Frame Header Version
    dwfenc eh_frame_pointer_encoding; // Exception Handler Frame Pointer Encoding
    dwfenc eh_frame_desc_entry_count_encoding; // Encoding of # of Exception Handler FDEs
    dwfenc eh_frame_table_encoding; // Exception Handler Table Encoding
};

typedef struct fde_table_entry fde_table_entry, *Pfde_table_entry;

struct fde_table_entry {
    dword initial_loc; // Initial Location
    dword data_loc; // Data location
};

typedef ulong size_t;

typedef enum Elf64_DynTag {
    DT_AUDIT=1879047932,
    DT_AUXILIARY=2147483645,
    DT_BIND_NOW=24,
    DT_CHECKSUM=1879047672,
    DT_CONFIG=1879047930,
    DT_DEBUG=21,
    DT_DEPAUDIT=1879047931,
    DT_ENCODING=32,
    DT_FEATURE_1=1879047676,
    DT_FILTER=2147483647,
    DT_FINI=13,
    DT_FINI_ARRAY=26,
    DT_FINI_ARRAYSZ=28,
    DT_FLAGS=30,
    DT_FLAGS_1=1879048187,
    DT_GNU_CONFLICT=1879047928,
    DT_GNU_CONFLICTSZ=1879047670,
    DT_GNU_HASH=1879047925,
    DT_GNU_LIBLIST=1879047929,
    DT_GNU_LIBLISTSZ=1879047671,
    DT_GNU_PRELINKED=1879047669,
    DT_HASH=4,
    DT_INIT=12,
    DT_INIT_ARRAY=25,
    DT_INIT_ARRAYSZ=27,
    DT_JMPREL=23,
    DT_MOVEENT=1879047674,
    DT_MOVESZ=1879047675,
    DT_MOVETAB=1879047934,
    DT_NEEDED=1,
    DT_NULL=0,
    DT_PLTGOT=3,
    DT_PLTPAD=1879047933,
    DT_PLTPADSZ=1879047673,
    DT_PLTREL=20,
    DT_PLTRELSZ=2,
    DT_POSFLAG_1=1879047677,
    DT_PREINIT_ARRAYSZ=33,
    DT_REL=17,
    DT_RELA=7,
    DT_RELACOUNT=1879048185,
    DT_RELAENT=9,
    DT_RELASZ=8,
    DT_RELCOUNT=1879048186,
    DT_RELENT=19,
    DT_RELSZ=18,
    DT_RPATH=15,
    DT_RUNPATH=29,
    DT_SONAME=14,
    DT_STRSZ=10,
    DT_STRTAB=5,
    DT_SYMBOLIC=16,
    DT_SYMENT=11,
    DT_SYMINENT=1879047679,
    DT_SYMINFO=1879047935,
    DT_SYMINSZ=1879047678,
    DT_SYMTAB=6,
    DT_TEXTREL=22,
    DT_TLSDESC_GOT=1879047927,
    DT_TLSDESC_PLT=1879047926,
    DT_VERDEF=1879048188,
    DT_VERDEFNUM=1879048189,
    DT_VERNEED=1879048190,
    DT_VERNEEDNUM=1879048191,
    DT_VERSYM=1879048176
} Elf64_DynTag;

typedef enum Elf_ProgramHeaderType {
    PT_DYNAMIC=2,
    PT_GNU_EH_FRAME=1685382480,
    PT_GNU_RELRO=1685382482,
    PT_GNU_STACK=1685382481,
    PT_INTERP=3,
    PT_LOAD=1,
    PT_NOTE=4,
    PT_NULL=0,
    PT_PHDR=6,
    PT_SHLIB=5,
    PT_TLS=7
} Elf_ProgramHeaderType;

typedef struct Elf64_Dyn Elf64_Dyn, *PElf64_Dyn;

struct Elf64_Dyn {
    enum Elf64_DynTag d_tag;
    qword d_val;
};

typedef struct Elf64_Phdr Elf64_Phdr, *PElf64_Phdr;

struct Elf64_Phdr {
    enum Elf_ProgramHeaderType p_type;
    dword p_flags;
    qword p_offset;
    qword p_vaddr;
    qword p_paddr;
    qword p_filesz;
    qword p_memsz;
    qword p_align;
};

typedef struct Elf64_Shdr Elf64_Shdr, *PElf64_Shdr;

typedef enum Elf_SectionHeaderType {
    SHT_CHECKSUM=1879048184,
    SHT_DYNAMIC=6,
    SHT_DYNSYM=11,
    SHT_FINI_ARRAY=15,
    SHT_GNU_ATTRIBUTES=1879048181,
    SHT_GNU_HASH=1879048182,
    SHT_GNU_LIBLIST=1879048183,
    SHT_GNU_verdef=1879048189,
    SHT_GNU_verneed=1879048190,
    SHT_GNU_versym=1879048191,
    SHT_GROUP=17,
    SHT_HASH=5,
    SHT_INIT_ARRAY=14,
    SHT_NOBITS=8,
    SHT_NOTE=7,
    SHT_NULL=0,
    SHT_PREINIT_ARRAY=16,
    SHT_PROGBITS=1,
    SHT_REL=9,
    SHT_RELA=4,
    SHT_SHLIB=10,
    SHT_STRTAB=3,
    SHT_SUNW_COMDAT=1879048187,
    SHT_SUNW_move=1879048186,
    SHT_SUNW_syminfo=1879048188,
    SHT_SYMTAB=2,
    SHT_SYMTAB_SHNDX=18
} Elf_SectionHeaderType;

struct Elf64_Shdr {
    dword sh_name;
    enum Elf_SectionHeaderType sh_type;
    qword sh_flags;
    qword sh_addr;
    qword sh_offset;
    qword sh_size;
    dword sh_link;
    dword sh_info;
    qword sh_addralign;
    qword sh_entsize;
};

typedef struct Elf64_Sym Elf64_Sym, *PElf64_Sym;

struct Elf64_Sym {
    dword st_name;
    byte st_info;
    byte st_other;
    word st_shndx;
    qword st_value;
    qword st_size;
};

typedef struct Elf64_Rela Elf64_Rela, *PElf64_Rela;

struct Elf64_Rela {
    qword r_offset; // location to apply the relocation action
    qword r_info; // the symbol table index and the type of relocation
    qword r_addend; // a constant addend used to compute the relocatable field value
};

typedef struct Elf64_Ehdr Elf64_Ehdr, *PElf64_Ehdr;

struct Elf64_Ehdr {
    byte e_ident_magic_num;
    char e_ident_magic_str[3];
    byte e_ident_class;
    byte e_ident_data;
    byte e_ident_version;
    byte e_ident_pad[9];
    word e_type;
    word e_machine;
    dword e_version;
    qword e_entry;
    qword e_phoff;
    qword e_shoff;
    dword e_flags;
    word e_ehsize;
    word e_phentsize;
    word e_phnum;
    word e_shentsize;
    word e_shnum;
    word e_shstrndx;
};

typedef struct evp_pkey_ctx_st evp_pkey_ctx_st, *Pevp_pkey_ctx_st;

struct evp_pkey_ctx_st {
};

typedef struct evp_pkey_ctx_st EVP_PKEY_CTX;




int _init(EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
  iVar1 = __gmon_start__();
  return iVar1;
}



void __cxa_finalize(void)

{
  __cxa_finalize();
  return;
}



void __isoc99_fscanf(void)

{
  __isoc99_fscanf();
  return;
}



// WARNING: Unknown calling convention yet parameter storage is locked

int puts(char *__s)

{
  int iVar1;
  
  iVar1 = puts(__s);
  return iVar1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

size_t strlen(char *__s)

{
  size_t sVar1;
  
  sVar1 = strlen(__s);
  return sVar1;
}



void __stack_chk_fail(void)

{
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



void _start(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 in_stack_00000000;
  undefined auStack8 [8];
  
  __libc_start_main(main,in_stack_00000000,&stack0x00000008,__libc_csu_init,__libc_csu_fini,param_3,
                    auStack8);
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



// WARNING: Removing unreachable block (ram,0x00101103)
// WARNING: Removing unreachable block (ram,0x0010110f)

void deregister_tm_clones(void)

{
  return;
}



// WARNING: Removing unreachable block (ram,0x00101144)
// WARNING: Removing unreachable block (ram,0x00101150)

void register_tm_clones(void)

{
  return;
}



void __do_global_dtors_aux(void)

{
  if (completed_8060 != '\0') {
    return;
  }
  __cxa_finalize(__dso_handle);
  deregister_tm_clones();
  completed_8060 = 1;
  return;
}



void frame_dummy(void)

{
  register_tm_clones();
  return;
}



undefined8 check_flag(char *param_1)

{
  size_t sVar1;
  undefined8 uVar2;
  
  sVar1 = strlen(param_1);
  if (sVar1 == 0x1d) {
    if (param_1[0x13] == '6') {
      param_1[6] = param_1[6] + '\x03';
      if (param_1[0x10] == 'n') {
        param_1[0x14] = param_1[0x14] + -8;
        param_1[0x1a] = param_1[0x1a] + -6;
        if (param_1[0xd] == 'r') {
          if (param_1[0x14] == '%') {
            if (param_1[0xf] == 'n') {
              if (param_1[10] == 'p') {
                param_1[0x10] = param_1[0x10] + '\a';
                if (param_1[0x10] == 'u') {
                  if (param_1[3] == '{') {
                    param_1[9] = param_1[9] + '\x01';
                    if (param_1[0x13] == '6') {
                      if (param_1[0x15] == 'q') {
                        if (param_1[0x15] == 'q') {
                          if (param_1[2] == 'n') {
                            param_1[0xc] = param_1[0xc] + -1;
                            if (*param_1 == 's') {
                              if (*param_1 == 's') {
                                if (param_1[7] == 'l') {
                                  if (param_1[0xe] == 'u') {
                                    param_1[0x11] = param_1[0x11] + '\x06';
                                    param_1[5] = param_1[5] + '\x05';
                                    if (param_1[0xc] == ',') {
                                      param_1[0x16] = param_1[0x16] + '\x05';
                                      param_1[0x11] = param_1[0x11] + -8;
                                      param_1[3] = param_1[3] + '\x05';
                                      param_1[0x10] = param_1[0x10] + -4;
                                      if (param_1[0xf] == 'n') {
                                        if (param_1[0xe] == 'u') {
                                          param_1[7] = param_1[7] + -9;
                                          if (param_1[4] == 'b') {
                                            if (param_1[0xe] == 'u') {
                                              param_1[0x18] = param_1[0x18] + -10;
                                              *param_1 = *param_1 + -3;
                                              if (param_1[6] == 'o') {
                                                param_1[0xb] = param_1[0xb] + '\a';
                                                param_1[1] = param_1[1] + -2;
                                                param_1[0x19] = param_1[0x19] + '\x05';
                                                if (param_1[0x12] == 'n') {
                                                  if (param_1[7] == 'c') {
                                                    param_1[0x18] = param_1[0x18] + -8;
                                                    param_1[0x12] = param_1[0x12] + -9;
                                                    param_1[0x14] = param_1[0x14] + -4;
                                                    if (param_1[0x16] == 'z') {
                                                      param_1[6] = param_1[6] + -9;
                                                      param_1[10] = param_1[10] + '\a';
                                                      param_1[0x14] = param_1[0x14] + '\x04';
                                                      if (param_1[0xf] == 'n') {
                                                        param_1[0x18] = param_1[0x18] + '\b';
                                                        param_1[0x13] = param_1[0x13] + -2;
                                                        param_1[0x19] = param_1[0x19] + '\a';
                                                        if (param_1[2] == 'n') {
                                                          if (param_1[0x17] == '1') {
                                                            *param_1 = *param_1 + -8;
                                                            if (param_1[0x14] == '%') {
                                                              if (param_1[1] == 's') {
                                                                if (param_1[6] == 'f') {
                                                                  param_1[0x14] =
                                                                       param_1[0x14] + '\x04';
                                                                  if (param_1[2] == 'n') {
                                                                    if (param_1[0x18] == 'Y') {
                                                                      param_1[0x17] =
                                                                           param_1[0x17] + -5;
                                                                      if (param_1[0x1c] == '}') {
                                                                        param_1[9] = param_1[9] +
                                                                                     '\x02';
                                                                        param_1[0x16] =
                                                                             param_1[0x16] + -6;
                                                                        param_1[8] = param_1[8] +
                                                                                     '\x03';
                                                                        if (param_1[10] == 'w') {
                                                                          param_1[0x11] =
                                                                               param_1[0x11] + '\t';
                                                                          if (param_1[0x10] == 'q')
                                                                          {
                                                                            if (*param_1 == 'h') {
                                                                              if (param_1[4] == 'b')
                                                                              {
                                                                                param_1[0xc] = 
                                                  param_1[0xc] + -2;
                                                  param_1[0xd] = param_1[0xd] + -4;
                                                  param_1[0x10] = param_1[0x10] + -4;
                                                  if (param_1[2] == 'n') {
                                                    param_1[9] = param_1[9] + -7;
                                                    param_1[7] = param_1[7] + '\b';
                                                    param_1[8] = param_1[8] + '\x04';
                                                    param_1[0xd] = param_1[0xd] + -10;
                                                    param_1[0x1a] = param_1[0x1a] + '\a';
                                                    if (param_1[0xe] == 'u') {
                                                      if (param_1[0x16] == 't') {
                                                        if (param_1[2] == 'n') {
                                                          param_1[0xf] = param_1[0xf] + -3;
                                                          if (param_1[0x1a] == 'm') {
                                                            param_1[6] = param_1[6] + '\x05';
                                                            param_1[0x13] = param_1[0x13] + -10;
                                                            param_1[0x1c] = param_1[0x1c] + '\x04';
                                                            if (param_1[6] == 'k') {
                                                              param_1[3] = param_1[3] + -9;
                                                              if (param_1[6] == 'k') {
                                                                param_1[0x11] = param_1[0x11] + -5;
                                                                param_1[0x11] = param_1[0x11] + -6;
                                                                if (param_1[1] == 's') {
                                                                  if (param_1[0x12] == 'e') {
                                                                    param_1[4] = param_1[4] + '\x05'
                                                                    ;
                                                                    if (param_1[6] == 'k') {
                                                                      if (param_1[0xc] == '*') {
                                                                        if (param_1[2] == 'n') {
                                                                          if (param_1[0x18] == 'Y')
                                                                          {
                                                                            param_1[6] = param_1[6]
                                                                                         + -7;
                                                                            if (param_1[0x17] == ','
                                                                               ) {
                                                                              if (param_1[0x15] ==
                                                                                  'q') {
                                                                                param_1[0x1c] =
                                                                                     param_1[0x1c] +
                                                                                     -8;
                                                                                *param_1 = *param_1 
                                                  + '\x03';
                                                  param_1[3] = param_1[3] + -9;
                                                  param_1[0xf] = param_1[0xf] + '\x03';
                                                  param_1[8] = param_1[8] + -9;
                                                  if (param_1[2] == 'n') {
                                                    if (param_1[0x1b] == 'y') {
                                                      if (param_1[0x1c] == 'y') {
                                                        if (param_1[0x13] == '*') {
                                                          if (param_1[8] == 'f') {
                                                            if (param_1[0x1c] == 'y') {
                                                              if (param_1[9] == ',') {
                                                                if (param_1[2] == 'n') {
                                                                  if (param_1[0xd] == 'd') {
                                                                    if (param_1[0x16] == 't') {
                                                                      if (param_1[5] == '8') {
                                                                        if (param_1[7] == 'k') {
                                                                          if (param_1[9] == ',') {
                                                                            if (param_1[1] == 's') {
                                                                              if (*param_1 == 'k') {
                                                                                if (param_1[8] ==
                                                                                    'f') {
                                                                                  if (param_1[1] ==
                                                                                      's') {
                                                                                    if (param_1[0x15
                                                  ] == 'q') {
                                                    if (param_1[0x1b] == 'y') {
                                                      if (param_1[0x13] == '*') {
                                                        if (param_1[3] == 'n') {
                                                          if (param_1[0x14] == ')') {
                                                            if (param_1[0xc] == '*') {
                                                              if (param_1[0x17] == ',') {
                                                                if (param_1[3] == 'n') {
                                                                  if (param_1[0x16] == 't') {
                                                                    if (param_1[0x1c] == 'y') {
                                                                      if (param_1[6] == 'd') {
                                                                        if (param_1[2] == 'n') {
                                                                          if (*param_1 == 'k') {
                                                                            if (*param_1 == 'k') {
                                                                              if (param_1[8] == 'f')
                                                                              {
                                                                                if (param_1[0x13] ==
                                                                                    '*') {
                                                                                  if (param_1[0xe]
                                                                                      == 'u') {
                                                                                    if (param_1[7]
                                                                                        == 'k') {
                                                                                      if (param_1[
                                                  0x18] == 'Y') {
                                                    if (param_1[0x19] == 'w') {
                                                      if (param_1[0x11] == '-') {
                                                        if (param_1[4] == 'g') {
                                                          if (param_1[0x17] == ',') {
                                                            if (param_1[5] == '8') {
                                                              if (param_1[0xc] == '*') {
                                                                if (param_1[0x1b] == 'y') {
                                                                  if (param_1[0xe] == 'u') {
                                                                    if (param_1[8] == 'f') {
                                                                      if (param_1[0xc] == '*') {
                                                                        if (param_1[4] == 'g') {
                                                                          if (param_1[0x1c] == 'y')
                                                                          {
                                                                            if (param_1[8] == 'f') {
                                                                              if (param_1[0x1c] ==
                                                                                  'y') {
                                                                                if (param_1[0xc] ==
                                                                                    '*') {
                                                                                  if (param_1[3] ==
                                                                                      'n') {
                                                                                    if (param_1[8]
                                                                                        == 'f') {
                                                                                      if (param_1[
                                                  0x19] == 'w') {
                                                    if (param_1[3] == 'n') {
                                                      if (param_1[6] == 'd') {
                                                        if (param_1[7] == 'k') {
                                                          if (param_1[0x19] == 'w') {
                                                            if (param_1[0xb] == '<') {
                                                              if (param_1[0x1b] == 'y') {
                                                                if (param_1[0xd] == 'd') {
                                                                  if (param_1[0x1b] == 'y') {
                                                                    uVar2 = 1;
                                                                  }
                                                                  else {
                                                                    uVar2 = 0;
                                                                  }
                                                                }
                                                                else {
                                                                  uVar2 = 0;
                                                                }
                                                              }
                                                              else {
                                                                uVar2 = 0;
                                                              }
                                                            }
                                                            else {
                                                              uVar2 = 0;
                                                            }
                                                          }
                                                          else {
                                                            uVar2 = 0;
                                                          }
                                                        }
                                                        else {
                                                          uVar2 = 0;
                                                        }
                                                      }
                                                      else {
                                                        uVar2 = 0;
                                                      }
                                                    }
                                                    else {
                                                      uVar2 = 0;
                                                    }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                  }
                                                  else {
                                                    uVar2 = 0;
                                                  }
                                                }
                                                else {
                                                  uVar2 = 0;
                                                }
                                              }
                                              else {
                                                uVar2 = 0;
                                              }
                                            }
                                            else {
                                              uVar2 = 0;
                                            }
                                          }
                                          else {
                                            uVar2 = 0;
                                          }
                                        }
                                        else {
                                          uVar2 = 0;
                                        }
                                      }
                                      else {
                                        uVar2 = 0;
                                      }
                                    }
                                    else {
                                      uVar2 = 0;
                                    }
                                  }
                                  else {
                                    uVar2 = 0;
                                  }
                                }
                                else {
                                  uVar2 = 0;
                                }
                              }
                              else {
                                uVar2 = 0;
                              }
                            }
                            else {
                              uVar2 = 0;
                            }
                          }
                          else {
                            uVar2 = 0;
                          }
                        }
                        else {
                          uVar2 = 0;
                        }
                      }
                      else {
                        uVar2 = 0;
                      }
                    }
                    else {
                      uVar2 = 0;
                    }
                  }
                  else {
                    uVar2 = 0;
                  }
                }
                else {
                  uVar2 = 0;
                }
              }
              else {
                uVar2 = 0;
              }
            }
            else {
              uVar2 = 0;
            }
          }
          else {
            uVar2 = 0;
          }
        }
        else {
          uVar2 = 0;
        }
      }
      else {
        uVar2 = 0;
      }
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



undefined8 main(void)

{
  int iVar1;
  long in_FS_OFFSET;
  undefined local_58 [72];
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  puts("Hotel Orlando Door Puzzle v1");
  puts("----------------------------");
  puts(
      "This puzzle, provided by Hotel Orlando, is in place to give the bellhops enough time to get your luggage to you."
      );
  puts("We have really slow bellhops and so we had to put a serious _time sink_ in front of you.");
  puts("Have fun with this puzzle while we get your luggage to you!");
  puts("\n\t-Hotel Orlando Bellhop and Stalling Service\n");
  puts("Your guess, if you would be so kind: ");
  __isoc99_fscanf(stdin,&DAT_001031b6,local_58);
  iVar1 = check_flag(local_58);
  if (iVar1 == 1) {
    puts("I see you found the key, hopefully your bags are in your room by this point.");
  }
  else {
    puts(
        "Sadly, that is the incorrect key. If you would like, you could also sit in our lobby and wait."
        );
  }
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail();
  }
  return 0;
}



void __libc_csu_init(EVP_PKEY_CTX *param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  
  _init(param_1);
  lVar1 = 0;
  do {
    (*(code *)(&__frame_dummy_init_array_entry)[lVar1])((ulong)param_1 & 0xffffffff,param_2,param_3)
    ;
    lVar1 = lVar1 + 1;
  } while (lVar1 != 1);
  return;
}



void __libc_csu_fini(void)

{
  return;
}



void _fini(void)

{
  return;
}


