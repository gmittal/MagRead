#ifndef MAGDECODE_H
#define MAGDECODE_H

#include <QIODevice>
#include <QVarLengthArray>

#include "mslib.h"
#include "magcard.h"


class MagDecode : public QIODevice
{
	Q_OBJECT
	public:
		explicit MagDecode(QObject *parent = 0);
		void start();
		void stop();
		qint64 writeData( const char *data, qint64 dataLen );
		qint64 readData( char *data, qint64 len );

		void setTimeOut( int _timeOut );
		void setNorm( int _normOffset );
		void setAlgorithm( QString _algorithm );
	
	private:
		int silenceCount;
		bool noiseDetected;
		bool captureAudio;
		int timeOut;
		int defaultTimeOut;
		void processSwipe();

		int silenceThreshold;
		int normOffset;
		bool normOffsetFound;

		QString algorithm;

		QVarLengthArray<qint16> pcmData;

	signals:
		void cardRead( MagCard );
		void errorMsg( QString );

	public slots:
		void setThreshold( int threshold );

};

#endif // MAGDECODE_H
