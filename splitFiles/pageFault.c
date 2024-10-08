int VtoP( int VPageNo,int PO ){

    if (R[VPageNo]==0) PageFault(VPageNo);
    return (PPN[VPageN] << p) | PO; //shifting phys.page address by p (2^p) bits ( size of page ) to fit proper offset. (think of it perhaps the way it works with segmentation in x86, multiplying
                                    //the segment selector by the size of the segment descriptor to get the proper address within the global GDT)
}

/*handle a missing page*/
void PageFault( int VPageNo ){
    int i = SelectLRUPage(); //choose least recently
    //used page, if D flag is set for the selected page
    //entry, handler writes contents to secondary
    //storage, update the page Table to indicate the
    //virtual address that corresponded to that
    //Page is no longer resident. returns i, the index of the
    //selected page 
    
    if(D[i] == 1) WritePage(DiskAdr[i], PPN[i]);
    R[i]=0;//not resident

    PPN[VPageNo] = PPN[i];//exactly what explained
    //before. i is the index of the selected page to be
    //"replaced"!
    
    R[VPageNo] = 1; //page resident
    D[VPageNo] = 0;//not dirty since just been pulled
    //from secondary storage.
}
