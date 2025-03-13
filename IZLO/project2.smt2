(set-logic NIA)
(set-option :produce-models true)
(set-option :incremental true)

; Deklarace promennych pro vstupy
; ===============================

; Parametry
(declare-fun A () Int)
(declare-fun B () Int)
(declare-fun C () Int)
(declare-fun D () Int)
(declare-fun E () Int)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;; START OF SOLUTION ;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; XLOGIN: xpasekj00

; Zde doplnte vase reseni
(declare-fun X () Int)
(declare-fun Y () Int)
(declare-fun Z () Int)


 


;funkce na vypocet x
;x_0 = (A_0 * B_0)-(C_0 * 5)
(define-fun x_v ((A Int) (B Int) (C Int)) Int
  (- (* A B) (* 5 C))
)
(assert (= X (x_v A B C)))
;if(A_1 + E_1) < (D_1 + D_2){
;   y_0 = (B_1 * 3) + x   
;}else{
;   y_1 = (C_1 * 2) * x
;}
;funkce na vypocet y
(define-fun y_v ((X Int) (B Int) (C Int) (D Int) (E Int)) Int
  (ite (< (+ X E) (+ D D))
    (+ X (* 3 B))
    (* X (* 2 C))
  )
)
(assert (= Y (y_v X B C D E)))
;if(y_3 - 5 <= C){
;    z_0 = x_1 * A_1 - y_3 * B_2;
;else if (x_2 + 2 > D_2)
;   z_1 = (x_2 + A_2) * (y_4 + B_3);
;else{
;   z_2 = x_3 * B_4 + y_5 * A_3;    
;}
;}
;funkce na vypocet z
(define-fun z_v ((X Int) (Y Int) (A Int) (B Int) (C Int) (D Int)) Int
  (ite (<= (- Y 5) C)
    	(- (* X A) (* Y B))
    	(ite (> (+ X 2) D)
    		(* (+ X A) (+ Y B))
     		(+ (* X B) (* Y A))
   		)
  )
)
(assert (= Z (z_v X Y A B C D)))
(assert (not (or (<= D 0) (<= E 0))))

(assert (> Z (+ D E)))

;podminka zarucujici nejmensi mozny vysledek D + E
(assert (
  not (
    exists ((D_prime Int) (E_prime Int) (Y_prime Int) (Z_prime Int)) (
        and
            (< (+ D_prime E_prime) (+ D E))
            (> D_prime 0)
            (> E_prime 0)
            (= Y_prime (y_v X B C D_prime E_prime))
            (= Z_prime (z_v X Y_prime A B C D_prime))
            (> Z_prime (+ D_prime E_prime))
    )  
  )
))

; bonus:
;Varel
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;; END OF SOLUTION ;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; Testovaci vstupy
; ================

(echo "Test 1 - vstup A=1, B=1, C=3")
(echo "a) Ocekavany vystup je sat a D+E se rovna 17")
(check-sat-assuming (
  (= A 1) (= B 1) (= C 3)
))
(get-value (D E (+ D E)))

(echo "b) Neexistuje jine reseni nez 17, ocekavany vystup je unsat")
(check-sat-assuming (
  (= A 1) (= B 1) (= C 3) (distinct (+ D E) 17)
))

(echo "")
(echo "")

(echo "Test 2 - vstup A=5, B=2, C=5")
(echo "a) Ocekavany vystup je sat a D+E se rovna 18")
(check-sat-assuming (
  (= A 5) (= B 2) (= C 5)
))

(get-value (D E (+ D E)))
(echo "b) Neexistuje jine reseni nez 18, ocekavany vystup je unsat")
(check-sat-assuming (
  (= A 5) (= B 2) (= C 5) (distinct (+ D E) 18)
))

(echo "")
(echo "")

(echo "Test 3 - vstup A=100, B=15, C=1")
(echo "a) Ocekavany vystup je sat a D+E se rovna 2")
(check-sat-assuming (
  (= A 100) (= B 15) (= C 1)
))

(get-value (D E (+ D E)))
(echo "b) Neexistuje jine reseni nez 2, ocekavany vystup je unsat")
(check-sat-assuming (
  (= A 100) (= B 15) (= C 1) (distinct (+ D E) 2)
))

(echo "")
(echo "")

(echo "Test 4 - vstup A=5, B=5, C=3")
(echo "a) Ocekavany vystup je sat a D+E se rovna 2")
(check-sat-assuming (
  (= A 5) (= B 5) (= C 3)
))

(get-value (D E (+ D E)))
(echo "b) Neexistuje jine reseni nez 2, ocekavany vystup je unsat")
(check-sat-assuming (
  (= A 5) (= B 5) (= C 3) (distinct (+ D E) 2)
))

(echo "")
(echo "")

(echo "Test 5 - vstup A=1, B=1, C=1")
(echo "a) Ocekavany vystup je unsat")

(check-sat-assuming (
  (= A 1) (= B 1) (= C 1)
))

(echo "")
(echo "")

(echo "Test 6 - vstup A=4, B=5, C=3")
(echo "a) Ocekavany vystup je sat a D+E se rovna 2")
(check-sat-assuming (
  (= A 4) (= B 5) (= C 3)
))

(get-value (D E (+ D E)))
(echo "b) Neexistuje jine reseni nez 2, ocekavany vystup je unsat")
(check-sat-assuming (
  (= A 4) (= B 5) (= C 3) (distinct (+ D E) 2)
))

(echo "")
(echo "")

(echo "Test 7 - vstup A=0, B=0, C=0")
(echo "a) Ocekavany vystup je unsat")
(check-sat-assuming (
  (= A 0) (= B 0) (= C 0)
))

(echo "")
(echo "")

(echo "Test 8 - vstup A=100, B=-50, C=-75")
(echo "a) Ocekavany vystup je sat a D+E se rovna 4628")
(check-sat-assuming (
  (= A 100) (= B -50) (= C -75)
))

(get-value (D E (+ D E)))
(echo "b) Neexistuje jine reseni nez 4628, ocekavany vystup je unsat")
(check-sat-assuming (
  (= A 100) (= B -50) (= C -75) (distinct (+ D E) 4628)
))

(echo "")
(echo "")

(echo "Test 9 - vstup A=3, B=2, C=2")
(echo "a) Ocekavany vystup je sat a D+E se rovna 7")
(check-sat-assuming (
  (= A 3) (= B 2) (= C 2)
))

(get-value (D E (+ D E)))
(echo "b) Neexistuje jine reseni nez 7, ocekavany vystup je unsat")
(check-sat-assuming (
  (= A 3) (= B 2) (= C 2) (distinct (+ D E) 7)
))

(echo "")
(echo "")

(echo "Test 10 - vstup A=-100, B=-15, C=-90")
(echo "a) Ocekavany vystup je sat a D+E se rovna 977")
(check-sat-assuming (
  (= A -100) (= B -15) (= C -90)
))
(get-value (D E (+ D E)))
(echo "b) Neexistuje jine reseni nez 977, ocekavany vystup je unsat")
(check-sat-assuming (
  (= A -100) (= B -15) (= C -90) (distinct (+ D E) 977)
))
