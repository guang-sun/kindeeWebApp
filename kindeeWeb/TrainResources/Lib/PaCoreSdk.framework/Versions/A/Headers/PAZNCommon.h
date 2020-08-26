#ifndef PAZNSSZipCommon
#define PAZNSSZipCommon

/* pazntm_unz contain date/time info */
typedef struct pazntm_pazn_s
{
    unsigned int pazntm_sec;            /* seconds after the minute - [0,59] */
    unsigned int pazntm_min;            /* minutes after the hour - [0,59] */
    unsigned int pazntm_hour;           /* hours since midnight - [0,23] */
    unsigned int pazntm_mday;           /* day of the month - [1,31] */
    unsigned int pazntm_mon;            /* months since January - [0,11] */
    unsigned int pazntm_year;           /* years - [1980..2044] */
} pazntm_unz;

typedef struct pazn_file_info_s
{
    unsigned long version;              /* version made by                 2 bytes */
    unsigned long version_needed;       /* version needed to extract       2 bytes */
    unsigned long flag;                 /* general purpose bit flag        2 bytes */
    unsigned long compression_method;   /* compression method              2 bytes */
    unsigned long dosDate;              /* last mod file date in Dos fmt   4 bytes */
    unsigned long crc;                  /* crc-32                          4 bytes */
    unsigned long compressed_size;      /* compressed size                 4 bytes */
    unsigned long uncompressed_size;    /* uncompressed size               4 bytes */
    unsigned long size_filename;        /* filename length                 2 bytes */
    unsigned long size_file_extra;      /* extra field length              2 bytes */
    unsigned long size_file_comment;    /* file comment length             2 bytes */

    unsigned long disk_num_start;       /* disk number start               2 bytes */
    unsigned long internal_fa;          /* internal file attributes        2 bytes */
    unsigned long external_fa;          /* external file attributes        4 bytes */

    pazntm_unz tmu_date;
} pazn_file_info;

typedef struct pazn_global_info_s
{
    unsigned long number_entry;         /* total number of entries in
                                 the central dir on this disk */
    unsigned long size_comment;         /* size of the global comment of the zipfile */
} pazn_global_info;

#endif
