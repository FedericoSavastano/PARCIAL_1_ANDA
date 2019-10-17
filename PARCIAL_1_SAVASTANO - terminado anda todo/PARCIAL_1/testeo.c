

/*
case 5:
                    /**JUGADORES**/
                    /*
                    printf("\nDar de alta un Jugador\n");
                    confirmaSN=getChar("Ingresar un jugador? [ S / N ] \n");

                    if(confirmaSN=='s' || confirmaSN=='S'){
                        lugarVacioJugadores=buscarLugarVacioJugadores(listaJugadores,CANT_JUGADORES);
                        printf("lugar vacio jugadores es : %d\n",lugarVacioJugadores);

                        if(lugarVacioJugadores>-1 && listaJugadores!=NULL && CANT_JUGADORES<MAX_JUGADORES)
                        {

                            //int auxCodigoJugador;
                            char auxApellidoJugador[31];
                            char auxNombreJugador[31];
                            int auxCodigoEquipoJugador; //REVISAR SI ESTO TIENE QUE ESTAR LIGADO AL ESTRUC DE EQUIPOS
                            char auxSexo;
                            int codigoEquipo;
                            eFechaJugador auxFechaNacimiento;

                            if( getValidString( "Ingrese el apellido del jugador : ", "Apellido no valido \n", "Apellido demasiado largo \n", auxApellidoJugador, 31,3 ) ==0
                                    && ( getValidString( "Ingrese el nombre del jugador : ", " Nombre no valido \n", " Nombre demasiado largo \n", auxNombreJugador,31,3)  ==0 )

                            ){
                                auxSexo= getChar("Ingrese el sexo del jugador M o F : ");
                                if(validSexo(auxSexo)==0)
                                {
                                    if(   introducirFechaJugador2(auxFechaNacimiento) ==0  )
                                    {

                                       if(buscarEquipoPorCodigo(listaEquipos,CANT_EQUIPOS,codigoEquipo)>-1 )
                                       {

                                           auxCodigoJugador=incrementarID(&codigoJugadoresAcumulador);

                                        //if( ( agregarJugador(listaJugadores,CANT_JUGADORES,) ) == 0  )


                                       }//if(buscarEquipoPorCodigo(listaEquipos,CANT_EQUIPOS,codigoEquipo)>-1 )

                                    }else{printf("Fecha no valida");break;}//if(  ( introducirFechaJugador2(auxFechaNacimiento) ) ==0  )




                            }else{printf("Sexo no valido");break;}//if(auxSexo=='m' || auxSexo=='M' || auxSexo=='f' ||auxSexo'F')
                            }else{printf("Nombre no valido");break;}//if( getValidString( "Ingrese el apellido del jugador : ", "Apellido no valido \n", "Apellido demasiado largo \n", auxApellidoJugador, 31,3 ) ==0
                                   // && ( getValidString( "Ingrese el nombre del jugador : ", " Nombre no valido \n", " Nombre demasiado largo \n", auxNombreJugador,31,3)  ==0 )

                        }else{printf("no hay mas lugar");break;}//if(lugarVacioJugadores>-1 && listaJugadores!=NULL && CANT_JUGADORES<MAX_JUGADORES)
                    }else{printf("saliendo"); break;}//if(confirmaSN=='s' || confirmaSN=='S')










                        break;

                    }








                    PRIMERA VERSION

                    /**JUGADORES**/
                    /*
                    printf("\nDar de alta un Jugador\n");
                    confirmaSN=getChar("Ingresar un jugador? [ S / N ] \n");

                    if(confirmaSN=='s' || confirmaSN=='S'){
                        lugarVacioJugadores=buscarLugarVacioJugadores(listaJugadores,CANT_JUGADORES);
                        printf("lugar vacio jugadores es : %d\n",lugarVacioJugadores);

                        if(lugarVacioJugadores>-1 && listaJugadores!=NULL && CANT_JUGADORES<MAX_JUGADORES)
                        {

                            //int auxCodigoJugador;
                            char auxApellidoJugador[31];
                            char auxNombreJugador[31];
                            int auxCodigoEquipoJugador; //REVISAR SI ESTO TIENE QUE ESTAR LIGADO AL ESTRUC DE EQUIPOS
                            char auxSexo;
                            int codigoEquipo;
                            eFechaJugador auxFechaNacimiento;

                            if( getValidString( "Ingrese el apellido del jugador : ", "Apellido no valido \n", "Apellido demasiado largo \n", auxApellidoJugador, 31,3 ) ==0
                                    && ( getValidString( "Ingrese el nombre del jugador : ", " Nombre no valido \n", " Nombre demasiado largo \n", auxNombreJugador,31,3)  ==0 )

                            ){
                                auxSexo= getChar("Ingrese el sexo del jugador M o F : ");
                                if( (auxSexo=='m' || auxSexo=='M') || (auxSexo=='f' ||auxSexo=='F') )
                                {
                                    if(   introducirFechaJugador2(auxFechaNacimiento[]) ==0  )
                                    {

                                       if(buscarEquipoPorCodigo(listaEquipos,CANT_EQUIPOS,codigoEquipo)>-1 )
                                       {

                                           auxCodigoJugador=incrementarID(&codigoJugadoresAcumulador);

                                        //if( ( agregarJugador(listaJugadores,CANT_JUGADORES,) ) == 0  )


                                       }//if(buscarEquipoPorCodigo(listaEquipos,CANT_EQUIPOS,codigoEquipo)>-1 )

                                    }//if(  ( introducirFechaJugador2(auxFechaNacimiento) ) ==0  )




                            }//if(auxSexo=='m' || auxSexo=='M' || auxSexo=='f' ||auxSexo'F')
                            }//if( getValidString( "Ingrese el apellido del jugador : ", "Apellido no valido \n", "Apellido demasiado largo \n", auxApellidoJugador, 31,3 ) ==0
                                   // && ( getValidString( "Ingrese el nombre del jugador : ", " Nombre no valido \n", " Nombre demasiado largo \n", auxNombreJugador,31,3)  ==0 )

                        }//if(lugarVacioJugadores>-1 && listaJugadores!=NULL && CANT_JUGADORES<MAX_JUGADORES)
                    }//if(confirmaSN=='s' || confirmaSN=='S')










                        break;

                    } */
