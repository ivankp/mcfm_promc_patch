      logical function userincludedipole(nd, ppart, mcfm_result)
************************************************************************
*   "user" routine that gets called to allow the user to veto events
*   that might otherwise pass the MCFM cuts. 
*   
*   It can be used, e.g. to force MCFM to generate only events that are
*   above some large HT threshold, which comes in useful when trying to
*   get precision on the tails of some distributions.
*   
*   Variables passed are
*
*   - nd:           index of the dipole
*   - ppart:        momenta of incoming and outgoing particles
*   - mcfm_result:  the decision that was taken by mcfm about whether to keep
*                   this event
*
*   NB: if mcfm_result is .false., MCFM's jet finding may not have run, 
*       and anything in MCFM that depends on it (e.g. some dynamic scales) 
*       will misbehave. It is safer not to return .true. when
*       mcfm_result=.false.
************************************************************************
      implicit none
      include 'constants.f'
      include 'npart.f'
      integer          nd
      double precision ppart(mxpart,4)
      logical          mcfm_result

c--- take the MCFM result as the default return value      
      userincludedipole = mcfm_result

c--- example of code (using compact f90 notation) that places a cut on HT
c      if (sum(sqrt(sum(ppart(3:2+npart,1:2)**2,dim=2))) < 500d0) then
c         userincludedipole = .false.
c      end if
      end 



      subroutine userplotter(p, wt,wt2, nd)
************************************************************************
*   Subroutine that is called to allow the user to bin their own
*   histograms
*
*   Variables passed to this routine:
*   
*        p:  4-momenta of incoming partons(i=1,2), outgoing leptons and
*            jets in the format p(i,4) with the particles numbered
*            according to the input file and components labelled by
*            (px,py,pz,E)?
*   
*       wt:  weight of this event
*   
*      wt2:  weight^2 of this event
*   
*       nd:  an integer specifying the dipole number of this contribution
*            (if applicable), otherwise equal to zero
************************************************************************
      implicit none
      include 'constants.f'
      include 'ptilde.f'
      include 'npart.f'
      include 'nplot.f'
      include 'mxdim.f'
      include 'scale.f'
      include 'facscale.f'
      include 'PDFerrors.f'
c--- Added to keep track of number of momenta entries to be filled
      include 'part.f'
      include 'plabel.f'
      include 'wts_bypart.f'
      include 'is_functions_com.f'
      double precision p(mxpart,4)
      integer imaxmom,ipdf
      common/iarray/imaxmom,ipdf
      character*3 labelE,labelx,labely,labelz
      character*5 labelPDF
      double precision wt,wt2
      integer          nd
      integer itmx1,ncall1,itmx2,ncall2,itmxplots
      common/iterat/itmx1,ncall1,itmx2,ncall2

c--- if you don't need extra histograms, you don't need to touch this code.
c--- Follow the commented example below to see what kind of things
c--- you might want to do.
      double precision scale_store,facscale_store
      integer          pid,i,ieve
      double precision pdferr, htjet
      logical          first
      data first/.true./
      save first
      character*4 tag
      character*2 label
c
      if (first) then
        tag   = "book"
        ieve=0;
        scale_store=scale
        facscale_store=facscale

        imaxmom=npart
        if ((part.eq.'real').or.(part.eq.'tota').or.(part.eq.'todk'))
     .    imaxmom=imaxmom+1

c--- determine if we need space in array to store PDF weights
      ipdf=0
      if (PDFerrors) then
        ipdf= maxPDFsets
      endif

       if (PDFerrors) then
          WRITE(6,*) "PDF labels"
          do i=1,ipdf
          write(labelPDF,75) i
          WRITE(6,*) labelPDF
          enddo
   75 format('PDF',i2.2)
       endif

c      pass Nr iterations  iand total number per iteration     
       CALL PROMCmcfmINI(itmx2 ,ncall2)
 

c ---- end of first event
       first = .false.
      else                
         tag = "plot"
      end if
c      
c      ! each histogram has an index; nextnplot from the nplot common block
c      ! holds the info on the next available common block
c      iplot = nextnplot
c
c      ! ht is scalar pt sum of all outgoing particles -- accessed from
c      ! the ptilde common block
c      ht    = sum(sqrt(sum(ptilde   (nd,3:2+npart,1:2)**2,dim=2)))
c      
c      call bookplot(iplot,tag,'UserHT',ht,wt,wt2,0d0,1000d0,50d0,'lin'); 
       ieve = ieve + 1
C       write(*,100) 'eve=', iplot 
C 100  format (A,I5)



c--- If the event weight is zero, don't bother to add the n-tuple
      if (wt .eq. 0d0) then
        return
      endif


      CALL PROMCmcfmRUN(ieve,imaxmom,p, wt,wt2, nd);

      
      end 



      subroutine userwriteinfo(unitno,comment_string,xsec,xsec_err,itno)
************************************************************************
*   subroutine that gets called after MCFM has written its comments to 
*   one of the output files. It allows the user to write their own comments
*   to that same file
*
*   Variables passed to this routine:
*
*   - unitno: the unit number to which output is being sent
*   - comment_string: a comment character that precedes each line of output
*   - xsec, xsec: the cross section and its error (in case you care!)
*   - itno: the iteration number (0 at the end of the last iteration)
************************************************************************
      implicit none
      integer          unitno
      character*2      comment_string
      double precision xsec, xsec_err
      integer          itno
 
c      write(6,*) "have reached iteration number", itno
c      write(unitno,"(a,a)") comment_string, "ht cut > 500 GeV"
      end

c---- SSbegin
c----------------------------------------------------------
      subroutine userhistofin(xsec,xsec_err,itno,itmx)
c     This function allows for extra user-defined operations 
c     at the end of each iteration (itno>0) and at the end of 
c     the run of the program (itno=0).
      implicit none
      integer itno,itmx
      double precision xsec,xsec_err

      IF (itno.eq.0) THEN 
            write(6,*) "Chekanov: Start call to PROMCmcfmEND.."
            write(6,*) "Sleep for 2 sec"
            CALL Sleep(2)
            Call PROMCmcfmEND(xsec,xsec_err,itno,itmx) 
      END IF

      end
c---- SSend
