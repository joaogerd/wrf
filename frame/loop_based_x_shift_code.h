      p => grid%head_statevars%next
      DO WHILE ( ASSOCIATED( p ) ) 
        IF ( p%ProcOrient .NE. 'X' .AND. p%ProcOrient .NE. 'Y' ) THEN
          IF ( INDEX(TRIM(p%Stagger),'X') .GT. 0 ) THEN
            ipf = MIN(ipe,ide)
          ELSE
            ipf = MIN(ipe,ide-1)
          ENDIF
          IF ( p%Ndim .EQ. 2 ) THEN
            IF (      p%MemoryOrder(1:1) .EQ. 'X' .AND.  p%MemoryOrder(2:2) .EQ.  'Y' ) THEN
              IF      ( p%Type .EQ. 'r' ) THEN
                IF ( SIZE(p%rfield_2d,1)*SIZE(p%rfield_2d,2) .GT. 1 ) THEN
                  p%rfield_2d(ips:ipf,jms:jme) = p%rfield_2d(ips+px:ipf+px,jms:jme)
                ENDIF
              ELSE IF ( p%Type .EQ. 'd' ) THEN
                IF ( SIZE(p%dfield_2d,1)*SIZE(p%dfield_2d,2) .GT. 1 ) THEN
                  p%dfield_2d(ips:ipf,jms:jme) = p%dfield_2d(ips+px:ipf+px,jms:jme)
                ENDIF
              ELSE IF ( TRIM(p%Type) .EQ. 'i' ) THEN
                IF ( SIZE(p%ifield_2d,1)*SIZE(p%ifield_2d,2) .GT. 1 ) THEN
                  p%ifield_2d(ips:ipf,jms:jme) = p%ifield_2d(ips+px:ipf+px,jms:jme)
                ENDIF
              ELSE IF ( p%Type .EQ. 'l' ) THEN
                IF ( SIZE(p%lfield_2d,1)*SIZE(p%lfield_2d,2) .GT. 1 ) THEN
                  p%lfield_2d(ips:ipf,jms:jme) = p%lfield_2d(ips+px:ipf+px,jms:jme)
                ENDIF
              ENDIF
            ENDIF
          ELSE IF ( p%Ndim .EQ. 3 ) THEN
            IF (      p%MemoryOrder(1:1) .EQ. 'X' .AND.  p%MemoryOrder(3:3) .EQ.  'Y' ) THEN
              IF      ( p%Type .EQ. 'r' ) THEN
                IF ( SIZE(p%rfield_3d,1)*SIZE(p%rfield_3d,3) .GT. 1 ) THEN
                  p%rfield_3d(ips:ipf,:,jms:jme) = p%rfield_3d(ips+px:ipf+px,:,jms:jme)
                ENDIF
              ELSE IF ( p%Type .EQ. 'd' ) THEN
                IF ( SIZE(p%dfield_3d,1)*SIZE(p%dfield_3d,3) .GT. 1 ) THEN
                  p%dfield_3d(ips:ipf,:,jms:jme) = p%dfield_3d(ips+px:ipf+px,:,jms:jme)
                ENDIF
              ELSE IF ( p%Type .EQ. 'i' ) THEN
                IF ( SIZE(p%ifield_3d,1)*SIZE(p%ifield_3d,3) .GT. 1 ) THEN
                  p%ifield_3d(ips:ipf,:,jms:jme) = p%ifield_3d(ips+px:ipf+px,:,jms:jme)
                ENDIF
              ELSE IF ( p%Type .EQ. 'l' ) THEN
                CALL wrf_error_fatal( '3D logical arrays cannot be shifted for moving nests' )
              ENDIF
            ELSE IF (  p%MemoryOrder(1:2) .EQ. 'XY' ) THEN
              IF      ( p%Type .EQ. 'r' ) THEN
                IF ( SIZE(p%rfield_3d,1)*SIZE(p%rfield_3d,2) .GT. 1 ) THEN
                  p%rfield_3d(ips:ipf,jms:jme,:) = p%rfield_3d(ips+px:ipf+px,jms:jme,:)
                ENDIF
              ELSE IF ( p%Type .EQ. 'd' ) THEN
                IF ( SIZE(p%dfield_3d,1)*SIZE(p%dfield_3d,2) .GT. 1 ) THEN
                  p%dfield_3d(ips:ipf,jms:jme,:) = p%dfield_3d(ips+px:ipf+px,jms:jme,:)
                ENDIF
              ELSE IF ( p%Type .EQ. 'i' ) THEN
                IF ( SIZE(p%ifield_3d,1)*SIZE(p%ifield_3d,2) .GT. 1 ) THEN
                  p%ifield_3d(ips:ipf,jms:jme,:) = p%ifield_3d(ips+px:ipf+px,jms:jme,:)
                ENDIF
              ELSE IF ( p%Type .EQ. 'l' ) THEN
                CALL wrf_error_fatal( '3D logical arrays cannot be shifted for moving nests' )
              ENDIF
            ENDIF
          ELSE IF ( p%Ndim .EQ. 4 ) THEN
            IF (      p%MemoryOrder(1:1) .EQ. 'X' .AND.  p%MemoryOrder(3:3) .EQ.  'Y' ) THEN
              IF      ( p%Type .EQ. 'r' ) THEN
                IF ( SIZE(p%rfield_4d,1)*SIZE(p%rfield_4d,3) .GT. 1 ) THEN
                  DO itrace = PARAM_FIRST_SCALAR , p%num_table(grid%id)
                    p%rfield_4d(ips:ipf,:,jms:jme,itrace) = p%rfield_4d(ips+px:ipf+px,:,jms:jme,itrace)
                  ENDDO
                ENDIF
              ELSE IF ( p%Type .EQ. 'd' ) THEN
                IF ( SIZE(p%dfield_4d,1)*SIZE(p%dfield_4d,3) .GT. 1 ) THEN
                  DO itrace = PARAM_FIRST_SCALAR , p%num_table(grid%id)
                    p%dfield_4d(ips:ipf,:,jms:jme,itrace) = p%dfield_4d(ips+px:ipf+px,:,jms:jme,itrace)
                  ENDDO
                ENDIF
              ELSE IF ( p%Type .EQ. 'i' ) THEN
                IF ( SIZE(p%ifield_4d,1)*SIZE(p%ifield_4d,3) .GT. 1 ) THEN
                  DO itrace = PARAM_FIRST_SCALAR , p%num_table(grid%id)
                    p%ifield_4d(ips:ipf,:,jms:jme,itrace) = p%ifield_4d(ips+px:ipf+px,:,jms:jme,itrace)
                  ENDDO
                ENDIF
              ELSE IF ( p%Type .EQ. 'l' ) THEN
                CALL wrf_error_fatal( '4D logical arrays cannot be shifted for moving nests' )
              ENDIF
            ELSE IF (  p%MemoryOrder(1:2) .EQ. 'XY' ) THEN
              IF      ( p%Type .EQ. 'r' ) THEN
                IF ( SIZE(p%rfield_4d,1)*SIZE(p%rfield_4d,2) .GT. 1 ) THEN
                  DO itrace = PARAM_FIRST_SCALAR , p%num_table(grid%id)
                    p%rfield_4d(ips:ipf,jms:jme,:,itrace) = p%rfield_4d(ips+px:ipf+px,jms:jme,:,itrace)
                  ENDDO
                ENDIF
              ELSE IF ( p%Type .EQ. 'd' ) THEN
                IF ( SIZE(p%dfield_4d,1)*SIZE(p%dfield_4d,2) .GT. 1 ) THEN
                  DO itrace = PARAM_FIRST_SCALAR , p%num_table(grid%id)
                    p%dfield_4d(ips:ipf,jms:jme,:,itrace) = p%dfield_4d(ips+px:ipf+px,jms:jme,:,itrace)
                  ENDDO
                ENDIF
              ELSE IF ( p%Type .EQ. 'i' ) THEN
                IF ( SIZE(p%ifield_4d,1)*SIZE(p%ifield_4d,2) .GT. 1 ) THEN
                  DO itrace = PARAM_FIRST_SCALAR , p%num_table(grid%id)
                    p%ifield_4d(ips:ipf,jms:jme,:,itrace) = p%ifield_4d(ips+px:ipf+px,jms:jme,:,itrace)
                  ENDDO
                ENDIF
              ELSE IF ( p%Type .EQ. 'l' ) THEN
                CALL wrf_error_fatal( '4D logical arrays cannot be shifted for moving nests' )
              ENDIF
            ENDIF
          ENDIF
        ENDIF
        p => p%next
      ENDDO
