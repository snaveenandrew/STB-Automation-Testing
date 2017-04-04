#ifndef           GAP_MAP_H
#define           GAP_MAP_H

#include          "blobbox.h"
#include          "notdll.h"

class GAPMAP
{
  public:
    GAPMAP(  //constructor
           TO_BLOCK *block);

    ~GAPMAP () {                 //destructor
      if (map != NULL)
        free_mem(map); 
    }

    BOOL8 table_gap(               //Is gap a table?
                    INT16 left,    //From here
                    INT16 right);  //To here

  private:
    INT16 total_rows;            //in block
    INT16 min_left;              //Left extreme
    INT16 max_right;             //Right extreme
    INT16 bucket_size;           // half an x ht
    INT16 *map;                  //empty counts
    INT16 map_max;               //map[0..max_map]       defind
    BOOL8 any_tabs;
};

/*-----------------------------*/

extern BOOL_VAR_H (gapmap_debug, FALSE, "Say which blocks have tables");
extern BOOL_VAR_H (gapmap_use_ends, FALSE,
"Use large space at start and end of rows");
extern BOOL_VAR_H (gapmap_no_isolated_quanta, FALSE,
"Ensure gaps not less than 2quanta wide");
extern double_VAR_H (gapmap_big_gaps, 1.75, "xht multiplier");
#endif
