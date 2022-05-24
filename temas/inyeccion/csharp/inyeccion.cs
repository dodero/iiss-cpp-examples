using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.EntityFrameworkCore;
using PostInyeccion.Models;

namespace PostInyeccion
{
    class Program {
        static void Main(string[] args){

            //Generamos la clase que hara el trabajo
            GeneradorInformes clasegeneradore = new GeneradorInformes();

            //Obtenemos los datos desde el contexto
            using (PostDbContext contexto = new PostDbContext()){

                var profesores = contexto.Profesores.Include(x => x.Cursos)
                                        .ThenInclude(x => x.Alumnos).ToList();

                //Instanciamos la clase de envio de emails
                var emailSender = new EmailSender();
                generador.GenerarInforme(profesores, emailSender);
            }
        }
    }

    public class GeneradorInformes{

        public  void GenerarInforme(List profesores, IEmailSender emailSender) {

            var envioOK = emailSender.Enviar(profesores); 
            if(!envioOK) { 
                //Registramos el fallo
            }
        }
    }
}

interface envioemail{
    bool Enviar(List profesores);
}

public class EmailSender : envioemail{
    public bool Enviar(List profesores)
    {
        //Enviar correo
    }
}

//Inyección de dependencias en parámetros de constructor

var emailSender = new EmailSender();
GeneradorInformes generador = new GeneradorInformes(emailSender);

public class GeneradorInformes{

    //Dependencia para el envio de correos
    envioemail _enviaremail;

    //Pasamos la dependencia en el construcor
    public GeneradorInformes(envioemail enviaremail) {
        _enviaremail = enviaremail;
    }

    public void GenerarInforme(List profesores) {
        _enviaremail.Enviar(profesores);
    }
}

//Inyección de propiedades
 

 //Instanciamos la clase de envio de emails
var emailSender = new EmailSender();
GeneradorInformes generador = new GeneradorInformes();
generador.EmailSender = emailSender;
generador.GenerarInforme(profesores);

public class GeneradorInformes{
    //Propiedad con la dependencia
    public IEmailSender EmailSender { get; set; }
    public GeneradorInformes(){
    }

    public void GenerarInforme(List profesores){
        EmailSender.Enviar(profesores);
    }
}