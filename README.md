# ft__access

i tried to recreate the access() system call in c.



The access() system call checks the accessibility of the file named by the path argument for the
access permissions indicated by the mode argument.  The value of mode is either the bitwise-inclu-
sive OR of the access permissions to be checked (R_OK for read permission, W_OK for write permis-
sion, and X_OK for execute/search permission), or the existence test (F_OK).
