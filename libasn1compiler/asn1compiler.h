#ifndef	ASN1_COMPILER_H
#define	ASN1_COMPILER_H

#include <asn1parser.h>

enum asn1c_flags {
	A1C_NOFLAGS,
	/*
	 * Debug the compiler.
	 */
	A1C_DEBUG		= 0x000001L,
	/*
	 * Do not split the target output in several files, just print it.
	 * (Note: the output is not likely to be compilable in this case).
	 */
	A1C_PRINT_COMPILED	= 0x000002L,
	/*
	 * Generate only the tables for ASN.1 types,
	 * do not emit ASN.1 parsing support code.
	 */
	A1C_OMIT_SUPPORT_CODE	= 0x000004L,
	/*
	 * Use wide types by default (INTEGER_t etc) instead of native/long.
	 */
	A1C_USE_WIDE_TYPES	= 0x000008L,
	/*
	 * Do not use C99 extensions.
	 */
	A1C_NO_C99		= 0x000010L,
	/*
	 * Enable use of unnamed unions (non-portable feature).
	 */
	A1C_UNNAMED_UNIONS	= 0x000020L,
	/*
	 * Don't make the asn1_DEF_'s of structure members "static".
	 */
	A1C_ALL_DEFS_GLOBAL	= 0x000040L,
	/*
	 * Do not generate constraint checking code.
	 */
	A1C_NO_CONSTRAINTS	= 0x000080L,
	/*
	 * Generate type_id_PR_member things identifiers of id_PR_member.
	 */
	A1C_COMPOUND_NAMES	= 0x000100L,
	/*
	 * Do not generate courtesy #includes for external dependencies.
	 */
	A1C_NO_INCLUDE_DEPS	= 0x000200L,
	/*
	 * Compile members of CHOICE as indirect pointers.
	 */
	A1C_INDIRECT_CHOICE	= 0x000400L,
	/*
	 * -flink-skeletons
	 * Symlink support files rather than copy them.
	 */
	A1C_LINK_SKELETONS	= 0x000800L,
	/*
	 * -gen-PER
	 * Generate PER support code
	 */
	A1C_GEN_PER		= 0x001000L,
	/*
	 * -pdu={all|auto|Type}
	 * Generate PDU table
	 */
	A1C_PDU_ALL		= 0x002000L,
	A1C_PDU_AUTO		= 0x004000L,
	A1C_PDU_TYPE		= 0x008000L,
	/*
	 * -fincludes-quoted
	 * Avoid generating #include <foo>, generate "foo" instead.
	 */
	A1C_INCLUDES_QUOTED	= 0x010000L,
	/*
	 * -fline-refs
	 * Include ASN.1 module's line numbers in comments.
	 */
	A1C_LINE_REFS       	= 0x020000L,
	/*
	 * -Gmakefile
	 * Generate makefile sample
	 */
	A1C_MAKE 		= 0x040000L,
	/*
	 * -Gcmake
	 * Generate cmake CMakeLists.txt sample
	 */
	A1C_CMAKE 		= 0x080000L,
	/*
	 * -Gmakefile
	 * Generate makefile sample
	 */
	A1C_LXMAKE 		= 0x100000L,
};

/*
 * Compile the ASN.1 specification.
 */
int asn1_compile(asn1p_t *asn, const char *datadir, enum asn1c_flags,
	int argc, int optc, char **argv);

void asn1c__add_pdu_type(const char *typename);

#endif	/* ASN1_COMPILER_H */
