#ifndef __HC_DEF_H__
#define __HC_DEF_H__

#define ERRIFGOTO( result, label )  if( result != NO_ERROR ){ goto label; }

#define ERRASSIGN( result, data )   { result = data; }
#define ERRASSIGNGOTO( result, data, label )    if( result != NO_ERROR ) { result = data; goto label; }


#define SAFEFREE( memory )  if( memory != NULL ) { free( memory ); memory = NULL; }
#define SAFECLOSE( fd )     if( fd > 0 ) { close( fd ); fd = -1 }


#endif