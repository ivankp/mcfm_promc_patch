C S.Chekanov. MCFMRUN example
C      PROGRAM MCFMRUN 
C      call determinefilenames(inputfile,workdir)
C      call mcfmmain(inputfile,workdir)
C      CALL PROMCEND
C      END


C called from ./src/User/usercode_f77.f 
      SUBROUTINE PROMCmcfmINI(itmx2,ncall2)
 

C communicate 
      integer inode
      CHARACTER(LEN=7) :: snode 
      common/promcmpi/inode,snode


      integer nproc
      double precision sqrts
      common/nproc/nproc
      common/energy/sqrts

c     Nr of iterations and events per iteration
      integer itmx2,ncall2 
 
      include 'werkdir.f'
 
      character*30 runstring
      common/runstring/runstring

      CHARACTER (len=50) :: filename;
 
      WRITE(6,*) "Initialization of ProMC. Call to PROMCmcfmINI"
      WRITE(6,*) workdir
      WRITE(6,*) inode 
c      filename=TRIM(werkdir)//"/"//TRIM(runstring)//".promc"
c      filename=TRIM(runstring)//".promc"
c      filename="/home/chakanau/bgheplib/bghep/physics/MCFM/BinPromc/a.p"

      filename=TRIM(runstring)//'.promc'
      call PROMCINIT(inode, TRIM(filename), "MCFM 6.8",
     + itmx2,nproc,sqrts)
 

      END


C called from ./src/User/usercode_f77.f
      SUBROUTINE PROMCmcfmRUN(ieve,imaxm,p, wt,wt2, nd)
 
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
      integer          imaxm, nd
c--- if you don't need extra histograms, you don't need to touch this
code.
c--- Follow the commented example below to see what kind of things
c--- you might want to do.
      double precision uL,scale_store,facscale_store
      integer          PDF_R,nev,pid,i,ieve
      logical          first
      data first/.true./
      save first
      character*4 tag
      character*2 label
      double precision  pdferr
      double precision  totweight
      integer nevents
      common/promcevents/nevents

      if (first) then
       nev=0
       totweight=0
       first = .false.
      endif 


      IF (wt .eq. 0) GOTO 999


      nev=nev+1
      nevents=ieve

         if ((nev.le.10000.and.mod(nev,1000).eq.0).or.
     >   nev.gt.10000.and.mod(nev,10000).eq.0
     >   ) then
         write(6,*)
     +   '*xnev=',nev, "tot weight=",totweight
         endif

C start ProMC and create files in the memmory
C       Call PROMCSTART(nev);


c---  event weights
c     WRITE(6,*) ieve
      do i=1,imaxmom
      if ((p(i+2,1)**2+p(i+2,2)**2) .ge.1) then  
      pid=0
      label=plabel(i+2)
      if     (label .eq. 'nl') then
        pid=+12
      elseif (label .eq. 'na') then
        pid=-12
      elseif (label .eq. 'el') then
        pid=+11
      elseif (label .eq. 'ea') then
        pid=-11
      elseif (label .eq. 'ml') then
        pid=+13
      elseif (label .eq. 'ma') then
        pid=-13
      elseif (label .eq. 'tl') then
        pid=+15
      elseif (label .eq. 'ta') then
        pid=-15
      elseif (label .eq. 'bq') then
        pid=+5
      elseif (label .eq. 'ba') then
        pid=-5
      elseif (label .eq. 'pp') then
        pid=21      ! Use gluon label for any jet
      elseif (label .eq. 'ga') then
        pid=22
      elseif (label .eq. 'ig') then
c--- this is a dummy value: no particle id available
        pid=0
      else
        pid=0
      endif

c     WRITE(6,*)i,pid,p(i+2,1),p(i+2,2),p(i+2,3),p(i+2,4)
c     mass is not filled, so fill energy
      Call PROMCADDPARTICLE(pid,
     +     p(i+2,1),p(i+2,2),p(i+2,3),p(i+2,4))
      endif
      enddo


c      WRITE(6,*)imaxmom
c      WRITE(6,*)wt,sngl(wt_gg),sngl(wt_gq),sngl(wt_qq),sngl(wt_qqb)

c weights of this event
      Call PROMCADDFLOAT(wt);
      Call PROMCADDFLOAT(wt_gg);
      Call PROMCADDFLOAT(wt_gq);
      Call PROMCADDFLOAT(wt_qq);
      Call PROMCADDFLOAT(wt_qqb);

      totweight = totweight +wt;


       uL=1000.;

c other are for PDF errors
c      WRITE(6,*) PDFerrors,ipdf
      if (PDFerrors) then
C        WRITE(6,*) "Nr:",ipdf 
        do i=1,ipdf
C        pdferr=wt*PDFwgt(i)/PDFwgt(0)
C        WRITE(6,*) pdferr, wt, PDFwgt(i), PDFwgt(0) 
         pdferr=1.0-PDFwgt(i)/PDFwgt(0)
         PDF_R= NINT(uL*pdferr) 
C         WRITE(6,*) pdferr, PDF_R
          Call PROMCADDINT(PDF_R);
        enddo
      endif


c    finally, add this event with global weight 
      Call PROMCADDEVENT(wt)

 
  999 CONTINUE

      END


C called from ./src/User/usercode_f77.f
      SUBROUTINE PROMCmcfmEND(xsec,xsec_err,itno,itmx)

      integer itno,itmx
      double precision xsec,xsec_err
      double precision lumi

      integer nevents
      common/promcevents/nevents
      integer inode
      CHARACTER(LEN=7) :: snode
      common/promcmpi/inode,snode
      include 'werkdir.f'
      integer nproc
      character*30 runstring
      common/nproc/nproc
      common/runstring/runstring
      CHARACTER (len=50) :: filename;


      WRITE(6,*) "Number of iteration=",itmx
      WRITE(6,*) "Call to PROMCmcfmEND"
      WRITE(6,*) "Cross section (in fb) and error:"
      WRITE(6,*) xsec,sec_err 
      WRITE(6,*) "Total events=", nevents
      if (xsec .gt. 0) lumi=nevents/xsec
      WRITE(6,*) "Total lumi with weighted events=", lumi 


C     convert to pb 
C     adding statistics metadata, the '0' is for cross section
C     the file will be closed automatically
C we pass DBLE(itmx) as double  -this is  Nr of iterations
      call PROMCADDSTATS(xsec/1000.0,xsec_err/1000.,DBLE(itmx),nevents)

C     call rootwrite
      call PROMCCLOSE


      END

