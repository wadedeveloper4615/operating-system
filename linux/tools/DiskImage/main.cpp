#include "filesystem.h"
#include "FatData.h"

int main()
{
    //FileSystem fs1("C:\\projects\\linux\\tools\\DiskImage\\images\\floppy.img");
    //fs1.parse();
    //FileSystem fs("C:\\projects\\linux\\tools\\DiskImage\\images\\a.img",READ);
    //FileSystem fs3("C:\\projects\\linux\\tools\\DiskImage\\images\\fat16NoMbr.img",READ);
    //fs3.parse();
    //FileSystem fs4("C:\\projects\\linux\\tools\\DiskImage\\images\\fat16Mbr.img",READ);
    //fs4.parse();
    //FileSystem fs("C:\\projects\\linux\\tools\\DiskImage\\images\\fat32NoMbr.img",READ);
    //FileSystem fs("C:\\projects\\linux\\tools\\DiskImage\\images\\fat32Mbr.img",READ);
    //FileSystem fs("C:\\projects\\linux\\tools\\DiskImage\\images\\exfat.img",READ);
    FileSystem fs8("C:\\projects\\linux\\tools\\DiskImage\\images\\new.img");
    //fs8.createImage(512,2880);
    fs8.gatherDeviceInformation(FS_FAT12);
    printf("================================\n");
    return 0;
}
