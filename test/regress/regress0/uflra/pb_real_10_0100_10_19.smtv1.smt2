(set-option :incremental false)
(set-info :source "MathSat group")
(set-info :status sat)
(set-info :category "random")
(set-info :difficulty "3")
(set-logic QF_UFLRA)
(declare-fun f0_1 (Real) Real)
(declare-fun f0_2 (Real Real) Real)
(declare-fun f0_3 (Real Real Real) Real)
(declare-fun f0_4 (Real Real Real Real) Real)
(declare-fun f1_1 (Real) Real)
(declare-fun f1_2 (Real Real) Real)
(declare-fun f1_3 (Real Real Real) Real)
(declare-fun f1_4 (Real Real Real Real) Real)
(declare-fun x0 () Real)
(declare-fun x1 () Real)
(declare-fun x2 () Real)
(declare-fun x3 () Real)
(declare-fun x4 () Real)
(declare-fun x5 () Real)
(declare-fun x6 () Real)
(declare-fun x7 () Real)
(declare-fun x8 () Real)
(declare-fun x9 () Real)
(declare-fun P0 () Bool)
(declare-fun P1 () Bool)
(declare-fun P2 () Bool)
(declare-fun P3 () Bool)
(declare-fun P4 () Bool)
(declare-fun P5 () Bool)
(declare-fun P6 () Bool)
(declare-fun P7 () Bool)
(declare-fun P8 () Bool)
(declare-fun P9 () Bool)
(check-sat-assuming ( (let ((_let_0 (f0_2 x7 x6))) (let ((_let_1 (f0_1 x9))) (let ((_let_2 (f0_2 (f1_1 x9) (- (- (* (/ (- 0 13) 1) x7) (* 1.0 x6)) (* 15.0 x8))))) (let ((_let_3 (+ (+ (* 16.0 _let_1) (* 10.0 (- (- (* 23.0 x4) (* 22.0 x3)) (* 15.0 x9)))) (* 26.0 (- (+ (* 26.0 x9) (* 23.0 x7)) (* 22.0 x8)))))) (let ((_let_4 (- 0 9))) (let ((_let_5 (* 25.0 x2))) (let ((_let_6 (- (+ (* (/ (- 0 14) 1) x6) (* 1.0 (f1_1 x5))) (* 15.0 (f1_1 (- (- (* (/ (- 0 13) 1) x7) (* 1.0 x6)) (* 15.0 x8))))))) (let ((_let_7 (f0_1 x6))) (let ((_let_8 (+ (+ (* 3.0 x3) (* 4.0 x5)) (* 29.0 x0)))) (let ((_let_9 (< x4 24.0))) (let ((_let_10 (< x1 (/ (- 0 16) 1)))) (let ((_let_11 (< (- (- (* (/ (- 0 13) 1) x7) (* 1.0 x6)) (* 15.0 x8)) (/ (- 0 15) 1)))) (let ((_let_12 (< (- (- (* (/ (- 0 13) 1) x7) (* 1.0 x6)) (* 15.0 x8)) 3.0))) (let ((_let_13 (= (f0_1 x8) (+ (+ (* 10.0 x4) (* 18.0 x2)) (* 23.0 x5))))) (let ((_let_14 (- 0 1))) (let ((_let_15 (< x9 (/ _let_14 1)))) (let ((_let_16 (< x4 (/ (- 0 22) 1)))) (let ((_let_17 (< (f1_1 x2) 6.0))) (let ((_let_18 (< (f0_1 x5) 22.0))) (let ((_let_19 (< _let_3 22.0))) (let ((_let_20 (- 0 3))) (let ((_let_21 (< _let_3 23.0))) (let ((_let_22 (< x8 (/ _let_14 1)))) (let ((_let_23 (< x6 (/ (- 0 13) 1)))) (let ((_let_24 (< x4 (/ (- 0 24) 1)))) (let ((_let_25 (< (f1_1 x3) (/ (- 0 16) 1)))) (let ((_let_26 (< (- (- (* 10.0 x9) (* 11.0 x5)) (* 3.0 x3)) 28.0))) (let ((_let_27 (< (f1_2 x8 (f1_1 x9)) 26.0))) (let ((_let_28 (< (f0_1 x2) 27.0))) (let ((_let_29 (< _let_7 (/ (- 0 7) 1)))) (let ((_let_30 (= (+ (+ (* 10.0 x4) (* 18.0 x2)) (* 23.0 x5)) _let_2))) (let ((_let_31 (< _let_2 24.0))) (let ((_let_32 (< _let_6 12.0))) (let ((_let_33 (< (f0_2 x7 x0) (/ (- 0 2) 1)))) (let ((_let_34 (= x5 _let_8))) (let ((_let_35 (< (f0_2 x3 x1) 6.0))) (let ((_let_36 (< _let_0 (/ (- 0 14) 1)))) (let ((_let_37 (< (- (- (* (/ (- 0 12) 1) x1) (* 14.0 _let_1)) (* 24.0 x3)) (/ (- 0 11) 1)))) (let ((_let_38 (< (+ (+ (* 10.0 x4) (* 18.0 x2)) (* 23.0 x5)) 7.0))) (let ((_let_39 (< (f1_1 x5) (/ (- 0 18) 1)))) (let ((_let_40 (< (f1_1 (- (- (* (/ (- 0 13) 1) x7) (* 1.0 x6)) (* 15.0 x8))) (/ _let_20 1)))) (let ((_let_41 (< (+ (- (* 29.0 x9) (* 26.0 x3)) (* 27.0 x7)) (/ _let_14 1)))) (let ((_let_42 (< _let_6 11.0))) (let ((_let_43 (= _let_8 (- (+ (* (/ _let_4 1) x8) (* 19.0 x9)) _let_5)))) (let ((_let_44 (= _let_2 (- (- (* 10.0 x9) (* 11.0 x5)) (* 3.0 x3))))) (let ((_let_45 (< (- (- (* 23.0 x4) (* 22.0 x3)) (* 15.0 x9)) (/ (- 0 29) 1)))) (let ((_let_46 (< (f1_1 x0) (/ _let_4 1)))) (let ((_let_47 (< (+ (+ (* 2.0 x3) _let_5) (* 27.0 x0)) 29.0))) (let ((_let_48 (not _let_23))) (let ((_let_49 (not _let_33))) (let ((_let_50 (not _let_32))) (let ((_let_51 (not _let_43))) (let ((_let_52 (not _let_38))) (let ((_let_53 (not _let_13))) (let ((_let_54 (not _let_35))) (let ((_let_55 (not _let_46))) (let ((_let_56 (not (< x7 (/ _let_20 1))))) (let ((_let_57 (not _let_16))) (let ((_let_58 (not _let_42))) (let ((_let_59 (not _let_25))) (let ((_let_60 (not (< (f0_1 x5) 21.0)))) (let ((_let_61 (not _let_15))) (let ((_let_62 (not (= x9 x5)))) (let ((_let_63 (not (< x5 (/ (- 0 25) 1))))) (let ((_let_64 (not (< _let_7 29.0)))) (let ((_let_65 (not _let_37))) (let ((_let_66 (or (not (< x2 (/ (- 0 26) 1))) _let_65))) (let ((_let_67 (not _let_19))) (let ((_let_68 (not _let_18))) (let ((_let_69 (not _let_26))) (let ((_let_70 (not (< (- (+ (* (/ (- 0 11) 1) x8) (* 26.0 _let_7)) (* 1.0 (f0_1 x8))) (/ (- 0 14) 1))))) (let ((_let_71 (not _let_24))) (let ((_let_72 (not _let_44))) (let ((_let_73 (not _let_30))) (let ((_let_74 (not _let_45))) (let ((_let_75 (not (= (f1_1 x2) (f0_2 x3 x1))))) (let ((_let_76 (not (< x6 (/ (- 0 15) 1))))) (let ((_let_77 (not _let_9))) (let ((_let_78 (not (< _let_6 17.0)))) (let ((_let_79 (not (< _let_1 27.0)))) (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (and (or (or _let_48 _let_49) _let_43) (or (or _let_26 _let_48) _let_25)) (or (or _let_50 _let_50) P9)) (or (or _let_51 _let_52) (not _let_17))) (or (or _let_33 _let_53) (< (f0_1 x5) 21.0))) (or (or (not P7) _let_54) _let_55)) (or (or _let_56 _let_44) P4)) (or (or _let_43 _let_57) _let_29)) (or (or (< _let_6 17.0) (not P1)) _let_58)) (or (or _let_18 _let_31) _let_59)) (or (or P2 _let_41) _let_45)) (or (or (not P5) _let_12) (not P7))) (or (or _let_60 (not P5)) _let_34)) (or (or _let_27 (< _let_1 27.0)) (not P8))) (or (or _let_28 _let_18) P8)) (or (or (< _let_6 17.0) _let_61) _let_37)) (or (or _let_51 (not _let_47)) _let_37)) (or (or _let_62 _let_63) _let_36)) (or (or _let_60 _let_58) (not P7))) (or (or _let_53 _let_17) P2)) (or (or _let_64 _let_51) _let_24)) (or (or _let_37 (< _let_6 17.0)) _let_25)) (or (or _let_24 _let_24) _let_55)) (or (or _let_56 _let_10) (not _let_28))) (or (or _let_55 _let_54) (< _let_1 27.0))) (or (or (< _let_6 17.0) _let_42) _let_34)) (or _let_66 _let_41)) (or (or P7 _let_39) _let_11)) (or (or _let_22 _let_57) _let_67)) (or (or P0 _let_45) _let_61)) (or (or _let_10 _let_28) _let_67)) (or (or _let_40 (not P2)) _let_32)) (or _let_66 (< _let_1 27.0))) (or (or (not _let_21) _let_26) _let_68)) (or (or _let_69 (not _let_40)) P4)) (or (or _let_41 (not _let_29)) _let_70)) (or (or _let_65 _let_71) _let_72)) (or (or P7 _let_55) P2)) (or (or (not _let_27) P1) P0)) (or (or _let_27 _let_11) _let_26)) (or (or _let_69 (= x9 x5)) (< x7 (/ _let_20 1)))) (or (or _let_73 _let_74) _let_69)) (or (or _let_13 _let_53) _let_72)) (or (or _let_53 _let_53) _let_44)) (or (or _let_41 _let_64) _let_36)) (or (or _let_36 _let_45) _let_59)) (or (or _let_12 _let_28) _let_17)) (or (or _let_73 _let_49) _let_51)) (or (or _let_31 P2) _let_64)) (or (or _let_9 _let_41) _let_70)) (or (or _let_75 _let_35) _let_45)) (or (or P7 (not P2)) _let_67)) (or (or _let_50 _let_23) P8)) (or (or _let_75 (not P4)) P0)) (or (or _let_61 _let_23) _let_30)) (or (or _let_47 _let_24) _let_18)) (or (or (not P8) _let_38) _let_70)) (or (or _let_52 _let_16) (not P8))) (or (or _let_30 _let_51) _let_11)) (or (or _let_70 _let_37) _let_56)) (or (or _let_76 _let_55) _let_44)) (or (or P8 (not _let_39)) _let_34)) (or (or _let_56 _let_70) (not P6))) (or (or _let_52 _let_38) _let_72)) (or (or _let_57 _let_65) _let_71)) (or (or _let_24 _let_60) _let_67)) (or (or _let_23 (= x9 x5)) _let_22)) (or (or (not P6) _let_31) (= x9 x5))) (or (or (< _let_1 27.0) _let_35) _let_30)) (or (or _let_50 (< x6 (/ (- 0 15) 1))) _let_12)) (or (or _let_26 _let_55) _let_63)) (or (or _let_59 (not P1)) _let_21)) (or (or _let_76 _let_29) _let_16)) (or (or (not _let_34) _let_76) _let_73)) (or (or _let_73 _let_19) _let_15)) (or (or _let_33 (not P4)) _let_35)) (or (or _let_47 _let_17) _let_74)) (or (or P8 _let_25) _let_35)) (or (or _let_69 _let_57) (not P7))) (or (or _let_30 P8) (< _let_6 17.0))) (or (or _let_58 _let_60) (not P9))) (or (or _let_63 _let_43) _let_62)) (or (or _let_77 _let_44) _let_26)) (or (or _let_58 _let_13) (not P6))) (or (or _let_37 _let_77) _let_62)) (or (or _let_28 _let_45) _let_58)) (or (or (not P8) _let_75) P6)) (or (or _let_9 _let_21) _let_53)) (or (or _let_18 _let_41) _let_78)) (or (or _let_75 (not P1)) _let_79)) (or (or _let_54 _let_61) _let_13)) (or (or P5 _let_69) (not _let_22))) (or (or (not _let_12) _let_77) _let_46)) (or (or _let_16 _let_23) _let_37)) (or (or _let_42 _let_35) _let_12)) (or (or _let_40 _let_79) P4)) (or (or _let_67 _let_35) _let_68)) (or (or _let_28 (< _let_0 22.0)) _let_78)) (or (or P0 _let_18) _let_24)) (or (or (not P0) _let_63) _let_32)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))) ))