/* Extracts structure info from Allegro for the assembly routines 
 * The code in this file is under the Giftware license, as it was
 * copyed off Allegro. Please see the copyright notice that comes
 * with Allegro for details.
 * Allegro is available at http://alleg.sf.net/
 */


#define USE_CONSOLE

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "allegro.h"

#if ALLEGRO_VERSION <= 3

#include "allegro/aintern.h"

#ifdef ALLEGRO_DOS
   #include "allegro/aintdos.h"
#endif
#else

#include "allegro/internal/aintern.h"

#ifdef ALLEGRO_DOS
   #include "allegro/platform/aintdos.h"
#endif

#endif


typedef struct {
   char *name;
   int value;
}offset_entry_t;

offset_entry_t list[] = {
#ifdef ALLEGRO_DJGPP
  {"##ALLEGRO_DJGPP", 0},
#endif
#ifdef ALLEGRO_WATCOM
  {"##ALLEGRO_WATCOM", 0},
#endif
#ifdef ALLEGRO_DOS
  {"##ALLEGRO_DOS", 0},
#endif
#ifdef ALLEGRO_WINDOWS
  {"##ALLEGRO_WINDOWS", 0},
#endif
#ifdef ALLEGRO_LINUX
  {"##ALLEGRO_LINUX", 0},
#endif
#ifdef ALLEGRO_LINUX_VBEAF
  {"##ALLEGRO_LINUX_VBEAF", 0},
#endif
#ifdef ALLEGRO_COLOR8
  {"##ALLEGRO_COLOR8", 0},
#endif
#ifdef ALLEGRO_COLOR16
  {"##ALLEGRO_COLOR16", 0},
#endif
#ifdef ALLEGRO_COLOR24
  {"##ALLEGRO_COLOR24", 0},
#endif
#ifdef ALLEGRO_COLOR32
  {"##ALLEGRO_COLOR32", 0},
#endif
#ifdef ALLEGRO_MMX
  {"##ALLEGRO_MMX", 0},
#endif
#ifdef ALLEGRO_NO_ASM
  {"##ALLEGRO_NO_ASM", 0},
#endif
  {"BMP_W",      (int)offsetof(BITMAP, w)},
  {"BMP_H",      (int)offsetof(BITMAP, h)},
  {"BMP_CLIP",   (int)offsetof(BITMAP, clip)},
  {"BMP_CL",     (int)offsetof(BITMAP, cl)},
  {"BMP_CR",     (int)offsetof(BITMAP, cr)},
  {"BMP_CT",     (int)offsetof(BITMAP, ct)},
  {"BMP_CB",     (int)offsetof(BITMAP, cb)},
  {"BMP_VTABLE", (int)offsetof(BITMAP, vtable)},
  {"BMP_WBANK",  (int)offsetof(BITMAP, write_bank)},
  {"BMP_RBANK",  (int)offsetof(BITMAP, read_bank)},
  {"BMP_DAT",    (int)offsetof(BITMAP, dat)},
  {"BMP_ID",     (int)offsetof(BITMAP, id)},
  {"BMP_EXTRA",  (int)offsetof(BITMAP, extra)},
  {"BMP_XOFFSET",(int)offsetof(BITMAP, x_ofs)},
  {"BMP_YOFFSET",(int)offsetof(BITMAP, y_ofs)},
  {"BMP_SEG",    (int)offsetof(BITMAP, seg)},
  {"BMP_LINE",   (int)offsetof(BITMAP, line)},
  {"NEWLINE", 0},
  {"#ifndef BMP_ID_VIDEO", 0}, // next lot are 0x%08X in original
  {"BMP_ID_VIDEO",    BMP_ID_VIDEO},
  {"BMP_ID_SYSTEM",   BMP_ID_SYSTEM},
  {"BMP_ID_SUB",      BMP_ID_SUB},
  {"BMP_ID_PLANAR",   BMP_ID_PLANAR},
  {"BMP_ID_NOBLIT",   BMP_ID_NOBLIT},
  {"BMP_ID_LOCKED",   BMP_ID_LOCKED},
  {"BMP_ID_AUTOLOCK", BMP_ID_AUTOLOCK},
  {"BMP_ID_MASK",     BMP_ID_MASK},
  {"#endif", 0 },
  {"NEWLINE", 0},
#ifndef ALLEGRO_USE_C
  {"CMP_PLANAR",      (int)offsetof(COMPILED_SPRITE, planar)},
  {"CMP_COLOR_DEPTH", (int)offsetof(COMPILED_SPRITE, color_depth)},
  {"CMP_DRAW",        (int)offsetof(COMPILED_SPRITE, proc)},
  {"NEWLINE", 0},
#endif
  {"VTABLE_COLOR_DEPTH", (int)offsetof(GFX_VTABLE, color_depth)},
  {"VTABLE_MASK_COLOR",  (int)offsetof(GFX_VTABLE, mask_color)},
  {"VTABLE_UNBANK",      (int)offsetof(GFX_VTABLE, unwrite_bank)},
  {"NEWLINE", 0},
  {"RLE_W",   (int)offsetof(RLE_SPRITE, w)},
  {"RLE_H",   (int)offsetof(RLE_SPRITE, h)},
  {"RLE_DAT", (int)offsetof(RLE_SPRITE, dat)},
  {"NEWLINE", 0},
  {"GFXRECT_WIDTH",  (int)offsetof(GRAPHICS_RECT, width)},
  {"GFXRECT_HEIGHT", (int)offsetof(GRAPHICS_RECT, height)},
  {"GFXRECT_PITCH",  (int)offsetof(GRAPHICS_RECT, pitch)},
  {"GFXRECT_DATA",   (int)offsetof(GRAPHICS_RECT, data)},
  {"NEWLINE", 0 }, 
  {"DRAW_SOLID",          DRAW_MODE_SOLID},
  {"DRAW_XOR",            DRAW_MODE_XOR},
  {"DRAW_COPY_PATTERN",   DRAW_MODE_COPY_PATTERN},
  {"DRAW_SOLID_PATTERN",  DRAW_MODE_SOLID_PATTERN},
  {"DRAW_MASKED_PATTERN", DRAW_MODE_MASKED_PATTERN},
  {"DRAW_TRANS",          DRAW_MODE_TRANS},
  {"NEWLINE", 0},
  {"#ifndef MASK_COLOR_8", 0},
  {"MASK_COLOR_8",   MASK_COLOR_8},
  {"MASK_COLOR_15",  MASK_COLOR_15},
  {"MASK_COLOR_16",  MASK_COLOR_16},
  {"MASK_COLOR_24",  MASK_COLOR_24},
  {"MASK_COLOR_32",  MASK_COLOR_32},
  {"#endif", 0},
  {"NEWLINE", 0},
  {"POLYSEG_U",       (int)offsetof(POLYGON_SEGMENT, u)},
  {"POLYSEG_V",       (int)offsetof(POLYGON_SEGMENT, v)},
  {"POLYSEG_DU",      (int)offsetof(POLYGON_SEGMENT, du)},
  {"POLYSEG_DV",      (int)offsetof(POLYGON_SEGMENT, dv)},
  {"POLYSEG_C",       (int)offsetof(POLYGON_SEGMENT, c)},
  {"POLYSEG_DC",      (int)offsetof(POLYGON_SEGMENT, dc)},
  {"POLYSEG_R",       (int)offsetof(POLYGON_SEGMENT, r)},
  {"POLYSEG_G",       (int)offsetof(POLYGON_SEGMENT, g)},
  {"POLYSEG_B",       (int)offsetof(POLYGON_SEGMENT, b)},
  {"POLYSEG_DR",      (int)offsetof(POLYGON_SEGMENT, dr)},
  {"POLYSEG_DG",      (int)offsetof(POLYGON_SEGMENT, dg)},
  {"POLYSEG_DB",      (int)offsetof(POLYGON_SEGMENT, db)},
  {"POLYSEG_Z",       (int)offsetof(POLYGON_SEGMENT, z)},
  {"POLYSEG_DZ",      (int)offsetof(POLYGON_SEGMENT, dz)},
  {"POLYSEG_FU",      (int)offsetof(POLYGON_SEGMENT, fu)},
  {"POLYSEG_FV",      (int)offsetof(POLYGON_SEGMENT, fv)},
  {"POLYSEG_DFU",     (int)offsetof(POLYGON_SEGMENT, dfu)},
  {"POLYSEG_DFV",     (int)offsetof(POLYGON_SEGMENT, dfv)},
  {"POLYSEG_TEXTURE", (int)offsetof(POLYGON_SEGMENT, texture)},
  {"POLYSEG_UMASK",   (int)offsetof(POLYGON_SEGMENT, umask)},
  {"POLYSEG_VMASK",   (int)offsetof(POLYGON_SEGMENT, vmask)},
  {"POLYSEG_VSHIFT",  (int)offsetof(POLYGON_SEGMENT, vshift)},
  {"POLYSEG_SEG  ",   (int)offsetof(POLYGON_SEGMENT, seg)},
  {"POLYSEG_ZBADDR",  (int)offsetof(POLYGON_SEGMENT, zbuf_addr)},
  {"POLYSEG_RADDR",   (int)offsetof(POLYGON_SEGMENT, read_addr)},
  {"NEWLINE", 0},
  {"ERANGE",          ERANGE},
  {"NEWLINE", 0},
  {"M_V00", (int)offsetof(MATRIX_f, v[0][0])},
  {"M_V01", (int)offsetof(MATRIX_f, v[0][1])},
  {"M_V02", (int)offsetof(MATRIX_f, v[0][2])},
  {"M_V10", (int)offsetof(MATRIX_f, v[1][0])},
  {"M_V11", (int)offsetof(MATRIX_f, v[1][1])},
  {"M_V12", (int)offsetof(MATRIX_f, v[1][2])},
  {"M_V20", (int)offsetof(MATRIX_f, v[2][0])},
  {"M_V21", (int)offsetof(MATRIX_f, v[2][1])},
  {"M_V22", (int)offsetof(MATRIX_f, v[2][2])},
  {"NEWLINE", 0},
  {"M_T0", (int)offsetof(MATRIX_f, t[0])},
  {"M_T1", (int)offsetof(MATRIX_f, t[1])},
  {"M_T2", (int)offsetof(MATRIX_f, t[2])},
  {"NEWLINE", 0},
#ifdef ALLEGRO_DOS
  {"IRQ_SIZE",    (int)sizeof(_IRQ_HANDLER)},
  {"IRQ_HANDLER", (int)offsetof(_IRQ_HANDLER, handler)},
  {"IRQ_NUMBER",  (int)offsetof(_IRQ_HANDLER, number)},
  {"IRQ_OLDVEC",  (int)offsetof(_IRQ_HANDLER, old_vector)},
  {"NEWLINE", 0},
  {"DPMI_AX",    (int)offsetof(__dpmi_regs, x.ax)},
  {"DPMI_BX",    (int)offsetof(__dpmi_regs, x.bx)},
  {"DPMI_CX",    (int)offsetof(__dpmi_regs, x.cx)},
  {"DPMI_DX",    (int)offsetof(__dpmi_regs, x.dx)},
  {"DPMI_SP",    (int)offsetof(__dpmi_regs, x.sp)},
  {"DPMI_SS",    (int)offsetof(__dpmi_regs, x.ss)},
  {"DPMI_FLAGS", (int)offsetof(__dpmi_regs, x.flags)},
  {"NEWLINE", 0},
#endif
#ifdef ALLEGRO_ASM_USE_FS
  {"#define USE_FS",     0},
  {"#define FSEG %fs:",  0},
#else
  {"#define FSEG",       0},
#endif
  {"NEWLINE", 0},

#ifdef ALLEGRO_ASM_PREFIX
#define PREFIX    ALLEGRO_ASM_PREFIX "##"
#else
#define PREFIX    ""
#endif
#ifdef ALLEGRO_WATCOM
  {"#define FUNC(name)            .globl " PREFIX "name ; nop ; _align_ ; " PREFIX "name:", 0},
#else
  {"#define FUNC(name)            .globl " PREFIX "name ; _align_ ; " PREFIX "name:", 0},
#endif
  {"#define GLOBL(name)           " PREFIX "name", 0},
  {"NEWLINE", 0},
  {NULL, 0}
  };

int main(int argc, char *argv[])
{
   offset_entry_t *p;
   FILE *f;

   if (argc < 2) {
      fprintf(stderr, "Usage: %s <output file>\n", argv[0]);
      return 1;
   }

   printf("writing structure offsets into %s...\n", argv[1]);

   f = fopen(argv[1], "w");
   if (f == 0) {
      fprintf(stderr, "%s: can not open file %s\n", argv[0], argv[1]);
      return 1;
   }

   fprintf(f, "/* automatically generated structure offsets for use by asm code */\n\n");


   p = list;
   while (p->name != NULL) {
      if (p->name[0] == '#') {
	 if (p->name[1] == '#') {
	    fprintf(f, "#ifndef %s\n#define %s\n#endif\n\n", p->name+2, p->name+2);
	 }
	 else fprintf(f, "%s\n", p->name);
      }
      else {
         fprintf(f, "#define %s %d\n", p->name, p->value);
      }
      p++;
   }

   if (ferror(f)) {
      fprintf(stderr, "%s: cannot write file %s\n", argv[0], argv[1]);
      return 1;
   }

   if (fclose(f)) {
      fprintf(stderr, "%s: cannot close file %s\n", argv[0], argv[1]);
      return 1;
   }

   return 0;
}

END_OF_MAIN();
