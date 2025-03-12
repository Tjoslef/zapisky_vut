(set-logic ALL)

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

; XLOGIN: xlogin00

; Zde doplnte vase reseni
 ;condition_0 = D_0 <= 0
  ;condition_1 = E_0 <= 0
  ;if(condition_0 || conditon_1){
      ;f=false
  ;}



 


;x_0 = (A_0 * B_0)-(C_0 * 5)
(define-fun x () Int
  (- (* A B) (* 5 C))
)
;if(A_1 + E_1) < (D_1 + D_2){
;   y_0 = (B_1 * 3) + x   
;}else{
;   y_1 = (C_1 * 2) + x
;}
;y_2 = phi(y_0,y_1)
(define-fun y () Int
  (ite (< (+ x E) (* 2 D))
       (+ x (* 3 B))
       (* x (* 2 C))
  )
)
;if(y_3 - 5 <= C){
;    z_0 = x_1 * A_1 - y_3 * B_2;
;else if (x_2 + 2 > D_2)
;   z_1 = (x_2 + A_2) * (y_4 + B_3);
;else{
;   z_2 = x_3 * B_4 + y_5 * A_3;    
;}
;}
; phi(z_0,z_1,z_2)
(define-fun z () Int
  (ite (<= (- y 5) C)
       (- (* x A) (* y B))
       (ite (> (+ x 2) D)
            (* (+ x A) (+ y B))
            (+ (* x B) (* y A))
       )
  )
)
 ; if (z_3 <= D_3 + E_2) {
;f=false
;  } else {
;f= true;
 ; }       
(assert (> z (+ D E)))
(assert (and (> D 0) (> E 0)))
(define-fun f ((D Int) (E Int)) Bool
  (and (> D 0) (> E 0) (> z (+ D E)))
)

;pro vsechny neexistuje D' a E' ktere jsou pravdive a jejich soucet je mensi nez D +E  
(assert (exists ((D Int) (E Int))
        (let ((sum (+ D E)))  
       (forall ((D_prime Int) (E_prime Int))
       ;vypocet y_prime z_prime y z  pro D a E abych zajistili ze D + E nejmensi mozne 
       ;tak udelame E_prime a D_prime ktere a porovnavame jestli je D + E mensi
         (let ((y_prime (ite (< (+ x E_prime) (* 2 D_prime))
                             (+ x (* 3 B))
                             (* x (* 2 C)))))
           (let ((z_prime (ite (<= (- y_prime 5) C)
                               (- (* x A) (* y_prime B))
                               (ite (> (+ x 2) D_prime)
                                    (* (+ x A) (+ y_prime B))
                                    (+ (* x B) (* y_prime A))))))
             (or (not (and (> D_prime 0)
                      (> E_prime 0)
                      (> z_prime (+ D_prime E_prime))))
            (>= (+ D_prime E_prime) sum)
           )
         )
       )
  )
)))
; Ověření splnitelnost konjunkce všech omezení.
(check-sat)

; Pokud je status 'sat', vypíše nalezený model.
(get-model)

; Pokud je status 'sat', vypíše hodnoty termů 'x', 'y' a 'x + y' v nalezeném modelu.
(get-value (D E (+ D E)))
; bonus:

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