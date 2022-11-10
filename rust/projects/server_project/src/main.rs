use std::io::{prelude::*, BufReader};
use std::net::{TcpListener, TcpStream};
fn main() {
    //127.0.0.1 represents our PC and 7878 is the choosed communication port
    let listener = TcpListener::bind("127.0.0.1:7878").unwrap();
    //bind will return a Result with TcpListener to that address or an error
    //by example any port under 1023 must cause an error, they need administrator privileges

    for stream in listener.incoming(){
        //incoming() returns a Result with a TcpStream or an error
        //a TcpStream represents a full connection between a server and a client (request and response)

        let stream = stream.unwrap();
        println!("Connection established");
        handle_connection(stream);
        //when a strem goes out of the scope the connection is closed(drop implementation)
    }
}
//a HTTP request takes this format:

//Method Request-URI HTTP-Version CRLF //first line of the request(Method = GET or POST, CRLF = \r\n)
//headers CRLF
//message-body

//a HTTP response takes this format:

//HTTP-Version Status-Code Reason-Phrase CRLF
//headers CRLF
//message-body

fn handle_connection(mut stream: TcpStream) {
    let buf_reader = BufReader::new(&mut stream);
    let http_request: Vec<_> = buf_reader
        .lines()
        .map(|result| result.unwrap()) //unwraping result from lines
        .take_while(|line| !line.is_empty()) //taking values until a empty string
        //a empty string indicates the end of the http request
        .collect(); //make this lines elements of a vec

    //println!("Request: {:#?}", http_request);

    //let response = "HTTP/1.1 200 OK\r\n\r\n"; //a simple response to client's request
    //with HTTP version, status-code(200 = standard success code), an OK and no headers or body

    let stats = "HTTP/1.1 200 OK";
    let content = std::fs::read_to_string("hello.html").unwrap();
    let content_size = content.len();

    let response = format!("{stats}\r\nContent lenght: {content_size}\r\n\r\n{content}");
    stream.write_all(response.as_bytes()).unwrap(); //send our response
}
