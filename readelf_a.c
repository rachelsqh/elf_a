struct Elf_INternal_Ehdr elf_header;



static int get_file_header(FILE *file)
{
	if(fread(elf_header.e_ident,EI_NIDENT,1,file) != 1)
		return 0;
	switch(elf_header.e_ident[EI_DATA]) {
	}

	is_32bit_elf = (elf_header.e_ident[EI_CLASS] != ELF

	if (is_32bit_elf) {
	    Elf32_External_Ehdr ehdr32;
	    if (fread(ehdr32.e_type,sizeof(ehdr32) - EI_NIDENT,1,file) != 1)
	    	return 0;

	    elf_header.e_type =
	    elf_header.e_machine =
	    elf_header.e_version = 
	    elf_header.e_entry =
	    elf_header.e_phoff =
	    elf_header.e_shoff =
	    elf_header.e_flags =
	    elf_header.e_ehsize =
	    elf_header.e_phentsize =
	    elf_header.e_phnum = 
	    elf_header.e_shstrndx = ;
	   } else {
		Elf64_External_Ehdr ehdr64;
		}
}


static int process_object(char *file_name,FILE *file)
{
	unsigned int i;
	if(!get_file_header(file))
		return -1;


	version_info[] =;


	process_file_header();

	process_section_headers(file);

	process_section_groups(file);

	process_prgram_headers(file);

	process_dynamic_section(file);

	process_reloc(file);
	process_unwind (file);
	proess_symbol_table(file);
	process_syminfo(file);
	
	process_version_sections (file);
	process_section_contents(file);
	process_notes (file);
	process_gnu_liblist(file);
	process_arch_specific (file);

}


int main(int argc,char *argv[])
{
	int err = 0;
	FILE *file = NULL;
	struct stat statbuf;
	char armag[SARMAG];
	int ret = 0;
	expandargv(&argc,&argv);
	parse_args(argc,argv);
	
	file = fopen (file_name,"rb");
	if(!file){
		perror("");
		return -1;
	}

	process_object(file_name,file);

	fclose(file);
	return 0;
}

