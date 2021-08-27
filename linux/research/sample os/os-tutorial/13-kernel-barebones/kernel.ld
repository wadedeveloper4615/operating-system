OUTPUT_FORMAT(win32)
ENTRY(START)
SECTIONS
{
    .text :{*(.text)}
    .data :{*(.data)}        
    .bss :{*(.bss)}
}