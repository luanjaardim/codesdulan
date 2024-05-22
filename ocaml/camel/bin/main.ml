(* Ocaml basic syntax, by luanjaardim *)

let _a = 1;;   (* defining a variable, underscore to ignore unused warning *)
let (a : int) = 1;;   (* defining a variable and it's type explicitily *)

let b = a + a in assert (b = 2);;   (* Defining inside a scope, b only exists inside the assertation *)
(* let c = b;; (* Uncomment this to see the error *) *)

(* Nested scopes definitions *)
let b = "100" in
  let c = 100 in
    let d = int_of_string b in
      if d != c then assert false else assert true;;

let i = 1 in
  let i = i + 1 in (* Inner Shadowing the outter i *)
    assert (i = 2);;

(* Function definition *)
let add a b = a + b in assert (add 1 1 = 2);;
(* Same as above *)
let add = fun a b -> a + b in assert (add 10 1 = 11);;
(* Same as above *)
let add = fun a -> fun b -> a + b in assert (add 20 1 = 21);;
(* Adding type notation *)
let add (a : int) (b : int) : int = a + b in assert (add 100 1 = 101);;

(* Recursive function *)
let rec factorial n =
  if n = 0 then 1 else n * factorial (n - 1) in
  assert (factorial 5 = 120)
;;

(* Functions are values in Ocaml, so they can be passed as parameters or returned by other functions *)
let derivative (f : float -> float) (dx : float) =
    fun (x : float) -> (f (x +. dx) -. f x) /. dx
  in
  let dx = 1e-6 in (* Using derivative with an already setted dx *)
  let d' = fun f -> derivative f dx in (* derivative function for our dx *)
  let sin' = d' sin in (* The calculated derivative of sin *)
  let cos' = d' cos in (* The calculated derivative of cos *)
  let pi = 4. *. atan 1. in
  (* Our calculated derivative of the sin has a precision of 9 decimals for the value of pi *)
  assert (Camel.Lib.round_dfrac 9 @@ sin' pi = cos pi);
  (* Our calculated derivative of cos the has a precision of 5 decimals for the value of pi *)
  assert (Camel.Lib.round_dfrac 5 @@ cos' pi =
          Camel.Lib.round_dfrac 15 @@ sin pi)
;;

(* Defining a Variant, a tagged union in ocaml *)
type _week_day = Monday | Tuesday | Wednesday | Thursday | Friday | Saturday | Sunday;;

(* Generic Pair, that can be Nothing *)
type ('a, 'b) pair = Pair of 'a * 'b | Nothing;;

(*'a and 'b are type holders, so you can have:*)
let _p = Pair (1, "pair");; (* here 'a = int and 'b = string *)
let _n = Nothing;;

(* Pattern Matching *)
let p = Pair ((1, 100), 5.5) in
  match p with
    | Pair ((x1, x2), y) -> assert (x1 + x2 = 101) ; assert (y != 0.0)
    | Nothing -> assert true

(* Creating a Record *)
type str = {
  content : string;
  len : int;
  (* Records can have mutable fields, but they are immutable by default *)
  mutable mutable_field : int (* This field can be assigned with the "<-" operator *)
}

(* Acessing position of str type and returning an char option, returns None if out of bounds *)
let strGet (s : str) (pos : int) : char option = 
  if pos < s.len && pos >= 0 then Some (String.get s.content pos) else None
;;

let my_s : str = 
  (* s is defined only to create my_str *)
  let s = "hello world" in
    { content = s; len = String.length s; mutable_field = 0 } (* Value of my_str *)
  in
    (* "@@" is the operator that pass everything at it's right as an argument to the left function *)
    assert ('d' = Option.get @@ strGet my_s 10);
    assert (Option.is_none @@ strGet my_s 11);
    my_s.mutable_field <- 1; (* Changing the mutable field *)

    (* Pattern matching Records *)
  let {content; len; mutable_field = m } = my_s in
      assert (content = "hello world");
      assert (len = String.length content);
      assert (m = 1);
;;

(* Loops, not very useful in Ocaml... *)
let first = 1 in
  let last = 10 in
    (* The body of for loops must always return the Unit '()'*)
    for i = first to last do i |> string_of_int |> Printf.printf "%s" done;
    (* |> is the pipe operator -> it pass the expression at left to the function at right *)
    print_newline ();
    for i = last downto first do i |> string_of_int |> Printf.printf "%s" done;
    print_newline ()
;;

let while_stop = ref false in
  while !while_stop do
    while_stop := !while_stop
  done
  (* while_stop is a reference to a value of type bool *)
  (* we can change it's value during the body of the while *)
  (* "!" access it's original value and ":=" assign through it's ref *)
;;

(* Changing part of the language by using
   the operator "<|" to pass a value to the left
   -- It does not works so good... *)
let (<|) = (@@);;

let _ =
  let do_nothing (_x : string) = () in
  let add1 num = 1 + num in
  do_nothing <| ( string_of_int <| add1 100 ) ;
  (* does not work without the parenthesis(with '@@' works) don't know why... *)
  do_nothing @@ string_of_int @@ add1 100
;;

(* Simple recursive factorial function *)
let rec fac n = if n == 0 then 1 else n * fac (n-1)
in assert (1 = fac 1) (* This will Overflow the Stack *)

let _ =
  (* Tail Recursive Function of the Factorial *)
  let fac n =
    (* Using an auxiliar function that contains a new parameter, that accumulates the answer *)
    let rec fac_aux n acc =
      if n = 0 then acc else fac_aux (n - 1) (n * acc)
      (* fac_aux is the last operation this function does, after the
         minus and multiplication, so we have an tail recursive function 
         the compiler can optimize it to a real loop, that does not overflow the stack *)
    in
    fac_aux n 1
  in
  assert (1 = fac 1) (* This will not Overflow the Stack *)
;;

(* Using the "and" keyword to define multiple functions *)
let _ =
  let rec even n =
      match n with
      | 0 -> true
      | x -> odd (x - 1)
    and odd n =
      match n with
      | 0 -> false
      | x -> even (x - 1)
    in
  assert (even 100);
  assert (odd 101)
(* These functions are mutually dependents, so they needed to be defined at the same time*)
;;

(* Lazy expressions *)
(* Used to only execute some computation when needed *)
let _ =
  let longRunTimeComputation = 
    lazy (
      Thread.delay 5. ;
      print_endline "Finished!" ;
      10 (*When forced to evaluate will return 10*)
    )
  in
  let fastRunTimeComputation = false in (* change this to true to evaluate longRunTimeComputation *)
  let maybeDoLongComputation =
    match fastRunTimeComputation, longRunTimeComputation with
      | false, _ -> ()
      | true, lazy v -> (
        (* longRunTimeComputation only will be evaluated if 
           the fastRunTimeComputation is true, without unecessary work! *)
        assert (v == 10);
        (* Lazy expression are memoized after use, so longRunTimeComputation 
           does not need to run again, btw we can for the evaluation with Lazy.force *)
        assert (Lazy.force longRunTimeComputation == 10)
      )
  in
  maybeDoLongComputation
;;

(* Labeled Functions *)
let f ~(func_to_apply_1:int -> int) : int = func_to_apply_1 1
  in assert (f ~func_to_apply_1:(fun x -> x + 1) = 2);;
    (* f is not a good name to tell what a function does, sometimes we can give more
       information about the function behave using labels, it will make the type of
       the function parameter have the parameter name, the type of f is: func_to_apply_1:(int -> int) -> int *)
let div ~dividend ~divisor = dividend / divisor
in assert (div ~dividend:10 ~divisor:2 = 5);;
(* the typs is: dividend:int -> divisor:int -> int *)

(* Optional parameters *)
(* If a function has an optional parameter, it won't be passed unless you explicitily pass it *)
let f (y: int) ?(default = 0) (x : int) : int = x + y + default in
  assert (f 1 1 = 2);
  assert (f ~default:10 1 1 = 12) (* The default value is setted to 10 *)
;;

(* An Optional parameter that has no default value is treated as an 'a option, that by default is None *)
let f ?op x = match op with
  | Some op -> x + op
  | None -> x
  in
  assert (f 1 = 1);
  assert (f ~op:10 1 = 11)
;;

(* TODO: Write about Polymorphic Variants *)
